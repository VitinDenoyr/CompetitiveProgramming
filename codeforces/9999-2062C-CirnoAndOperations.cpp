//https://codeforces.com/problemset/problem/2062/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 999000;
 
void solve(){
 
	ll n; cin >> n;
	vector<ll> a (n+1, 0);
	ll sum = 0; ll sz = n;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
 
	while(sz > 1){
		vector<ll> b (n+1, 0);
		ll summy = 0;
		for(ll i = 1; i <= sz-1; i++){
			b[i] = a[i+1] - a[i];
			summy += b[i];
		}
		sum = max(abs(summy), sum);
		for(ll i = 1; i <= sz-1; i++){
			a[i] = b[i];
		}
		sz--;
	}
 
	cout << sum << "\n";
	
}
 
int main(){
 
	ll t; cin >> t;
	while(t--){
		solve();
	}
 
	return 0;
}