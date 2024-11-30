//https://codeforces.com/problemset/problem/2036/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll xor1n(ll n){
	if(n%4 == 0) return n;
	if(n%4 == 1) return 1;
	if(n%4 == 2) return n+1;
	return 0;
}

void solve(){
	ll a,b,i,k; cin >> a >> b >> i >> k;
	ll xorAB = (xor1n(b) ^ xor1n(a-1));
	ll inicio = (a>>i), fim = (b>>i);
	if(a%(1ll<<i) > k) inicio++;
	if(b%(1ll<<i) < k) fim--;
	ll xorRuins = 0;
	if(inicio <= fim){
		xorRuins = ((xor1n(fim) ^ xor1n(inicio-1))<<i);
		if((inicio-fim)%2 == 0) xorRuins ^= k;
	}
	cout << (xorAB ^ xorRuins) << "\n";
}

int main(){

	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}