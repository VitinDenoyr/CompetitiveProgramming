//https://codeforces.com/contest/2119/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){

	ll n; cin >> n;
	ll a,b,c,d; cin >> a >> b >> c >> d;
	ll disty = (c-a)*(c-a) + (d-b)*(d-b);
	vector<ll> v (n+1, 0); ll mv = 0, sm = 0;
	for(ll i = 1; i <= n; i++){
		cin >> v[i];
		mv = max(mv,v[i]);
		sm += v[i];
	}

	ll distmin = max(mv - (sm-mv),0ll)*max(mv - (sm-mv),0ll);

	if(distmin <= disty && disty <= sm*sm){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}