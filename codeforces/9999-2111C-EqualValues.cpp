//https://codeforces.com/contest/2111/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
const ll INF = 1000000000000000000ll;

void solve(){

	ll n; cin >> n;
	vector<ll> a (n+1, 0);
	vector<ll> larg (n+1, 0);
	ll curr = 0, tot = 0;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != curr){
			larg[curr] = max(tot,larg[curr]);
			curr = a[i]; tot = 1;
		} else {
			tot++;
		}
	}
	larg[curr] = max(tot,larg[curr]);

	ll bestcost = INF;
	for(ll i = 1; i <= n; i++){
		if(larg[i] > 0){
			bestcost = min(bestcost, i*(n-larg[i]));
		}
	}
	cout << bestcost << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}