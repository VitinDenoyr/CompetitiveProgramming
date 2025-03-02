//https://codeforces.com/problemset/problem/2065/G
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
 
void solve(){
 
	ll n; cin >> n;
	
	//Define quem são os primos de 1 até N
	vector<bool> isPrime (n+1, 1); isPrime[1] = 0;
	for(ll i = 2; i <= n; i++){
		if(!isPrime[i]) continue;
		for(ll j = 2*i; j <= n; j += i){
			isPrime[j] = 0;
		}
	}
 
	vector<ll> a (n+1, 0), mult (n+1, 0), gpf (n+1, 0);
	
	//Entrada + Conta os primos totais com qtp + conta a frequência de cada valor em qt
	map<ll,ll> qt; ll qtp = 0;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		if(isPrime[a[i]]) qtp++;
		qt[a[i]]++;
	}
 
	//Se i é primo, então é um fator dos seus múltiplos. Usa isso e calcula maior fator primo de cada número.
	for(ll i = 2; i <= n; i++){
		if(!isPrime[i]) continue;
		for(ll j = i; j <= n; j += i){
			gpf[j] = i;
		}
	}
 
	//Para cada lleiro de 1 até N, conta quantos números da forma P*Q onde ambos são primos são multiplos dele
	for(ll i = 2; i <= n; i++){
		if(!isPrime[i]) continue;
		for(ll j = 2*i; j <= n; j += i){
			if(isPrime[j/gpf[j]]){
				mult[i] += qt[j];
			}
		}
	}
 
	ll r = 0, acc = 0;
	//Encontra quantos pares começam com p.first, onde p é cada valor que aparece no array
	for(pii p : qt){
		//Se p for primo, então só da pra formar pares com outros primos maiores (qtp*p.sec) ou com multiplos com 2 fatores primos (mult[p.first]*p.sec)
		if(isPrime[p.first]){
			qtp -= p.second;
			r += (mult[p.first] + qtp)*p.second;
		} else if(isPrime[p.first/gpf[p.first]]){ //Se for um número P*Q, então só da consigo mesmo
			r += (p.second*(p.second+1))/2;
		}
	}
	cout << r << "\n";
}
 
int main(){
 
	
	ll t; cin >> t;
	while(t--){
		solve();
	}
 
	return 0;
}