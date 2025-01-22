#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int main(){

	int k,k0; cin >> k; k0 = k;
	vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

	function<void(vector<pii>&, string)> print;
	print = [&](vector<pii>& v, string fr = "Vetor:"){
		cout << fr << "\n";
		for(int _ = 0; _ < v.size(); _++) cout << v[_].first << "^" << v[_].second << " | " << k0 << "\n";
	};

	//Decomposição sqrt(N)
	vector<pii> factors;
	for(int i = 2; i*i <= k; i++){
		int exp = 0;
		while(k%i == 0){
			k /= i;
			exp++;
		}
		if(exp > 0) factors.push_back({i,exp});
	}
	factors.push_back({k,1}); //Adiciona o fator primo faltante no final
	print(factors,"Decomposicao sqrt(N):");

	k = k0; factors.clear();

	//Usando crivo de maior divisor primo
	//Vantagem: Leva O(NloglogN) uma vez, mas calcula a fatoração todas as vezes em O(fatores)
	vector<int> biggestPrimeDiv (k+1, 0);
	for(int i = 2; i <= k; i++){
		if(biggestPrimeDiv[i] > 0) continue; //i não é primo
		for(int j = i; j <= k; j += i){
			biggestPrimeDiv[j] = i;
		}
	}
	int p = -1, exp = 0;
	while(k > 1){
		if(biggestPrimeDiv[k] != p){
			if(p != -1) factors.push_back({p,exp});
			p = biggestPrimeDiv[k]; exp = 1;
		} else {
			exp++;
		}
		k /= biggestPrimeDiv[k];
	}
	if(p != -1) factors.push_back({p,exp});
	print(factors,"Crivo de maior divisor primo:");

	return 0;
}