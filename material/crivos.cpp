#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	int n; cin >> n;

	function<void(vector<int>&, string, int)> print;
	print = [&](vector<int>& v, string fr = "Vetor:", int k = 10){
		cout << fr << "\n";
		for(int _ = 1; _ <= k; _++) cout << v[_] << " \n"[_==k];
	};

	// Crivo de Erastótenes
	// Encontra os primos em O(NLogLogN)
	vector<int> isPrime (n+1, 1); isPrime[1] = 0;
	for(int i = 2; i <= n; i++){
		if(!isPrime[i]) continue;
		for(int mult = 2*i; mult <= n; mult += i){
			isPrime[mult] = 0;
		}
	}
	print(isPrime,"Primos [1 ~ 20]:",20);

	// Crivo de quantidade de divisores
	// Encontra a quantidade de divisores de todos os números de 1 à N em O(NlogN)
	vector<int> qtDivisors (n+1, 0);
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j += i){
			qtDivisors[j]++;
		}
	}
	print(qtDivisors,"Quantidade de Divisores [1 ~ 20]:",20);

	// Crivo de soma dos divisores
	// Encontra a soma dos divisores de todos os números de 1 à N em O(NlogN)
	vector<int> sumDivisors (n+1, 0);
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j += i){
			sumDivisors[j] += i;
		}
	}
	print(sumDivisors,"Soma dos Divisores [1 ~ 20]:",20);

	// Crivo da função phi de Euler
	// Encontra os valores da função phi de Euler de 1 à N em O(NloglogN)
	// A função phi de Euler mostra quantos números menores que K são prios entre si com K
	vector<int> primesBetween (n+1, 0);
	for(int i = 1; i <= n; i++) primesBetween[i] = i;
	for(int i = 2; i <= n; i++){
		if(primesBetween[i] < i) continue; // i não é primo
		for(int j = i; j <= n; j += i){
			primesBetween[j] -= primesBetween[j] / i; // remove os múltiplos de i de j
		}
	}
	print(primesBetween, "Primos Entre Si [1 ~ 20]:", 20);

	// Crivo do maior divisor primo
	// Encontra o maior divisor primo dos números de 1 à N em O(NloglogN)
	vector<int> biggestPrimeDiv (n+1, 0);
	for(int i = 2; i <= n; i++){
		if(biggestPrimeDiv[i] > 0) continue; //i não é primo
		for(int j = i; j <= n; j += i){
			biggestPrimeDiv[j] = i;
		}
	}

	return 0;
}