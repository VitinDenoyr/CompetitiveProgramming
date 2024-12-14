#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define prllvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl
#define MAXN 100005

ll n,m;
vector<pll> adj[MAXN];
bool vis[MAXN];

int main(){

	cin >> n >> m;
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	for(ll i = 0; i < m; i++){
		ll a,b,c;
		cin >> a >> b >> c;
		adj[a].push_back({c,b});
		adj[b].push_back({c,a});
	}
	pq.push({0,1}); ll r = 0, qtVis = 0;
	while(!pq.empty()){
		pll nx = pq.top(); pq.pop();
		if(vis[nx.second]) continue;
		r += nx.first; vis[nx.second] = 1; qtVis++;
		for(pll v : adj[nx.second]){
			if(!vis[v.second]){
				pq.push(v);
			}
		}
	}
	if(qtVis == n){
		cout << r << "\n";
	} else {
		cout << "IMPOSSIBLE\n";
	}

	return 0;
}