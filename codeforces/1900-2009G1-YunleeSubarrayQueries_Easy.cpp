//https://codeforces.com/problemset/problem/2009/G1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>

int main(){

	ll t; cin >> t;
	while(t--){
		ll n,k,q; cin >> n >> k >> q;
		vector<ll> v (n+1),fq(2*n+1), resp(n+1); //v -> a[i]-i+(n-1). qt -> quantos caras tem o valor disso como i. fq -> quantos valores diferentes tem essa quantidade de aparições
		unordered_map<ll,ll> qt;
		fq[0] = 2*n+1;
	
		for(ll i = 1; i <= n; i++){
			cin >> v[i]; v[i] = v[i]-i;
		}

		ll ans = 0;
		for(ll i = 1; i <= k-1; i++){
			fq[qt[v[i]]]--;
			ans = max(ans, ++qt[v[i]]);
			fq[qt[v[i]]]++;
		}

		for(ll i = 1; i <= n-k+1; i++){
			fq[qt[v[i+k-1]]]--;
			ans = max(ans, ++qt[v[i+k-1]]);
			fq[qt[v[i+k-1]]]++;

			while(fq[ans] == 0){
				ans--;
			}
			resp[i] = k-ans;

			fq[qt[v[i]]]--;
			qt[v[i]]--;
			fq[qt[v[i]]]++;
		}

		for(ll i = 1; i <= q; i++){
			ll l,r; cin >> l >> r;
			cout << resp[l] << "\n";
		}
	}

	return 0;
}