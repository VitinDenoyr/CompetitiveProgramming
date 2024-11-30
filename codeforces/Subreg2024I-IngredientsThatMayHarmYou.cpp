//https://codeforces.com/gym/105327/problem/I
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAX = 1000001;
const int MAXN = 100001;
int pow2[100001] = {1};
 
int main(){
 
	int n; cin >> n;
	vector<int> v (n), freq(MAX,0);
	for(int i = 0; i < n; i++){
		cin >> v[i];
		freq[v[i]]++;
	}
	for(int i = 1; i <= MAXN; i++){
		pow2[i] = (2ll*pow2[i-1])%MOD;
	}
 
	vector<int> mult (MAX,0);
	for(int i = 2; i < MAX; i++){
		for(int j = i; j < MAX; j += i){
			mult[i] += freq[j];
		}
	}
 
	int queries; cin >> queries;
	for(int i = 0; i < queries; i++){
		int ans = n, p; cin >> p;
		//Encontre quantos numeros tem fator primo em comum com p e tire de ans
		vector<int> primes;
		for(int f = 2; f*f <= p; f++){ //Fatoração muito rápida: pior caso O(sqrt(N)), mas nesse pior caso, acelera o resto, então na prática é simplesmente >> bem rápido <<
			if(p%f == 0){
				primes.push_back(f);
				while(p%f == 0) p /= f;
			}
		}
		if(p > 1) primes.push_back(p);
		//Agora primes guarda os fatores primos de p. Preciso somar então para cada combinação deles quantos múltiplos dessa combinação tem, mas com soma alternada pelo principio de inclusão-exclusão: Soma se tem quantidade impar de fatores primos e subtrai caso contrário.
		int psize = primes.size(), sub = 0;
		for(int mask = (1 << psize)-1; mask >= 1; mask--){
			int prod = 1, sign = -1;
			//Dada uma configuração de primos escolhidos, veremos qual o produto deles
			for(int bit = 0; bit < psize; bit++){
				if(((1<<bit)&mask) != 0){
					prod *= primes[bit];
					sign *= -1; //Se ele deve ser somado ou subtraido para evitar repetições
				}
			}
			sub += mult[prod]*sign;
		}
		ans -= sub;
		//Calcula quantos subconjuntos de ans elementos existem
		cout << pow2[ans] << "\n";
	}
 
	return 0;
}