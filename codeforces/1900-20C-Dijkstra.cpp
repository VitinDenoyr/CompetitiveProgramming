//https://codeforces.com/problemset/problem/20/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
const ll INF = 1000000000000000LL;

void solve(){

	ll n,m; cin >> n >> m;
	vector<vector<pll>> adj (n+1, vector<pll>());

	for(int i = 1; i <= m; i++){
		ll a,b,c; cin >> a >> b >> c;
		adj[a].push_back({c,b});
		adj[b].push_back({c,a});
	}

	vector<ll> dist (n+1, INF), parent(n+1, -1);
	priority_queue<pll, vector<pll>, greater<pll>> pq;

	dist[1] = 0;
	pq.push({0, 1});

	while(!pq.empty()){
		auto [d, u] = pq.top(); pq.pop();
		if(d > dist[u]) continue;
		for(auto [w, v] : adj[u]){
			if(dist[v] > d + w){
				dist[v] = d + w;
				parent[v] = u;
				pq.push({dist[v], v});
			}
		}
	}

	if(dist[n] == INF){
		cout << -1 << "\n";
		return;
	}

	vector<ll> path;
	for(ll v = n; v != -1; v = parent[v]){
		path.push_back(v);
	}
	reverse(path.begin(), path.end());

	for(ll v : path){
		cout << v << " ";
	}
	cout << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t = 1;
	while (t--){
		solve();
	}
	return 0;

}