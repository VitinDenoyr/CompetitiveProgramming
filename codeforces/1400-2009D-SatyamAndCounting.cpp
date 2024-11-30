//https://codeforces.com/problemset/problem/2009/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ll t; cin >> t;
	while(t--){
		ll n, vr = 0; cin >> n;
		vector<ll> qt (n+1, 0);
		vector<vector<bool>> ex (n+1, vector<bool>(2,0));
		ll basis = 0;
		for(ll i = 0; i < n; i++){
			ll x,y; cin >> x >> y;
			ex[x][y] = true; qt[x]++;
			if(qt[x] == 2){
				basis++;
			}
		}
		for(ll i = 0; i <= n-2; i++){
			if(ex[i][0] && ex[i+1][1] && ex[i+2][0]) vr++;
			if(ex[i][1] && ex[i+1][0] && ex[i+2][1]) vr++;
		}

		//tem basis.size() bases.  Pra cada base, tenho (n-2) pontos
		cout << basis*(n-2) + (vr) << "\n";
	}

	return 0;
}