//https://codeforces.com/problemset/problem/2114/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

void solve(){

	ll n; cin >> n;
	vector<vector<ll>> adj (n+1, vector<ll>());
	vector<ll> a (n+1, 0);
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}

	for(ll i = 1; i < n; i++){
		ll x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	vector<ll> vis (n+1, 0), mini (n+1, 0), maxi (n+1, 0);
	function<ll(ll)> go = [&](ll u) -> ll{
		for(ll v : adj[u]){
			if(vis[v]) continue;
			maxi[v] = max(a[v], a[v] - mini[u]);
			mini[v] = min(a[v], a[v] - maxi[u]);
			//cout << v << " -> " << mini[v] << " x " << maxi[v] << "\n";
			vis[v] = 1;
			go(v);
		}
		return 0;
	};
	mini[1] = a[1]; maxi[1] = a[1]; vis[1] = 1;
	go(1);

	for(ll i = 1; i <= n; i++){
		cout << maxi[i] << " \n"[i==n];
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}