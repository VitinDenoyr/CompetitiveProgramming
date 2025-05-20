//https://codeforces.com/contest/698/problem/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007ll;

int main(){

	// Leitura do N e criação do vetor de posições.
	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll n; cin >> n;
	vector<ll> a (n+1, 0);
	
	// Calcula o fatorial dos números em O(N)
	vector<ll> fatorial (n+1, 1);
	for(int i = 2; i <= n; i++){
		fatorial[i] = (fatorial[i-1] * i)%mod;
	}

	// Maior divisor primo com Crivo de Eratóstenes: O(NloglogN)
	vector<int> maiorPrimoQueDivide (n+1, 0);
	for(int i = 2; i <= n; i++){
		if(maiorPrimoQueDivide[i] == 0){
			maiorPrimoQueDivide[i] = i;
			for(int j = 2*i; j <= n; j += i){
				maiorPrimoQueDivide[j] = i;
			}
		}
	}

	// Encontra a ordem dos números de 2 até N
	vector<int> ordem (n+1, 0);
	vector<int> qtPrimosDeOrdem (n/2+1, 0);
	for(int i = 2; i <= n; i++){
		ordem[i] = (n/i) - 1;
		if(maiorPrimoQueDivide[i] == i){
			qtPrimosDeOrdem[ordem[i]]++;
		}
	}

	// Encontra os primos na fatoração de cada número
	vector<vector<int>> fatoracao (n+1, vector<int>());
	vector<ll> produtoDaFatoracaoDe (n+1, 1);
	for(int i = 2; i <= n; i++){
		if(maiorPrimoQueDivide[i] == i){
			fatoracao[i].push_back(i);
			produtoDaFatoracaoDe[i] *= i;
		} else {
			// Coloca os mesmos fatores do divisor
			int divisor = i/maiorPrimoQueDivide[i];
			fatoracao[i] = fatoracao[divisor];
			produtoDaFatoracaoDe[i] = produtoDaFatoracaoDe[divisor];

			// Se esse primo for novo, coloca ele também
			if(divisor % maiorPrimoQueDivide[i] != 0){
				fatoracao[i].push_back(maiorPrimoQueDivide[i]);
				produtoDaFatoracaoDe[i] *= maiorPrimoQueDivide[i];
			}
		}
	}

	// Encontra quantos valores tem exatamente uma certa combinação de primos
	map<ll,ll> qtNumerosComProduto;
	for(int i = 2; i <= n; i++){
		qtNumerosComProduto[produtoDaFatoracaoDe[i]]++;
	}

	// Precisamos considerar o 1 como primo
	maiorPrimoQueDivide[1] = 1; ordem[1] = 0;
	qtPrimosDeOrdem[0]++; fatoracao[1] = {1};
	produtoDaFatoracaoDe[1] = 1; qtNumerosComProduto[1] = 1;

	// O primo pi (nas posições) foi substituído por:
	vector<int> posicao_i_tem (n+1, 0);
	// O primo qi (nos valores) está substituindo a posição:
	vector<int> primo_i_substituiu (n+1, 0);

	// Valida se uma posição "pos" pode ter valor "val"
	function<bool(int,int)> validacao = [&](int pos, int val) -> bool{
		// Vamos olhar primo a primo, do maior para o menor, pois primos
		// maiores possuem uma ordem igual ou menor que os menores
		int proximoPrimoPos = fatoracao[pos].size()-1;
		int proximoPrimoVal = fatoracao[val].size()-1;
		if(proximoPrimoPos != proximoPrimoVal) return false; // Bijeção Impossível

		// Repita enquanto houver primo para decidir
		while(proximoPrimoPos >= 0 || proximoPrimoVal >= 0){

			// Se o próximo primo de pos já tem valor definido:
			int c1 = posicao_i_tem[fatoracao[pos][max(proximoPrimoPos,0)]];
			if(proximoPrimoPos >= 0 && c1 != 0){
				// Se esse valor se encontra na substituição:
				if(val % c1 == 0){
					proximoPrimoPos--;
					continue;
				} else {
					return false;
				}
			}

			// Se o próximo primo de val já tem valor definido:
			int c2 = primo_i_substituiu[fatoracao[val][max(proximoPrimoVal,0)]];
			if(proximoPrimoVal >= 0 && c2 != 0){
				// Se esse valor se encontra na posição:
				if(pos % c2 == 0){
					proximoPrimoVal--;
					continue;
				} else {
					return false;
				}
			}
			
			// Se ambos não tem fator associado, então associa um ao outro
			if(proximoPrimoPos >= 0 && proximoPrimoVal >= 0){
				// Toma os primos que estamos vendo
				int pi = fatoracao[pos][proximoPrimoPos];
				int qi = fatoracao[val][proximoPrimoVal];
				
				// Devem ter a mesma ordem, ou a bijeção é impossível
				if(ordem[pi] == ordem[qi]){
					primo_i_substituiu[qi] = pi;
					posicao_i_tem[pi] = qi;
					qtPrimosDeOrdem[ordem[pi]]--; //Menos uma opção de substituição
					proximoPrimoPos--; proximoPrimoVal--;
					continue;
				} else {
					return false;
				}
			} else {
				// Impossível associar, então a bijeção é impossível
				return false;
			}
		}
		return true; // Conseguiu associar corretamente
	};

	// Leitura da entrada e verificação de compatibilidade dos primos
	bool impossivel = false;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(impossivel) continue;
		if(a[i] != 0){
			impossivel = !(validacao(i,a[i]));
			// Esse produto tem uma opção a menos já definida
			qtNumerosComProduto[produtoDaFatoracaoDe[i]]--;
		}
	}

	ll resposta = 1;
	if(impossivel){
		cout << 0 << "\n";
		return 0;
	} else {
		//Calcula as possíveis associações de primos restantes
		for(int i = 0; i < n/2; i++){
			resposta = (resposta * fatorial[qtPrimosDeOrdem[i]])%mod;
		}

		//Calcula as possíveis associações de posições com produto igual
		for(pair<ll,ll> x : qtNumerosComProduto){
			resposta = (resposta * fatorial[x.second])%mod;
		}

		cout << resposta << "\n";
	}

	return 0;

}