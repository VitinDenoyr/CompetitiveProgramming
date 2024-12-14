#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define MOD 1000000007
#define INF 100000000000000009
#define MAXN 100005
#define printvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl

ll n,m;
vector<pll> adj[MAXN], radj[MAXN];
ll dist[MAXN], qtPaths[MAXN], minL[MAXN], maxL[MAXN];
bool vis[MAXN];

int main(){
	cin >> n >> m;
	for(ll i = 0; i < m; i++){
		ll a,b,c;
		cin >> a >> b >> c;
		adj[a].push_back({c,b});
		radj[b].push_back({c,a});
	}
	for(ll i = 2; i <= n; i++){
		dist[i] = INF;
		minL[i] = MOD;
		maxL[i] = -1;
	}
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	dist[1] = 0; qtPaths[1] = 1;
	minL[1] = 0; maxL[1] = 0;
	for(pll v : adj[1]){
		dist[v.second] = v.first;
		pq.push({dist[v.second],v.second});
	}
	while(!pq.empty()){
		pll nxt = pq.top(); pq.pop();
		if(vis[nxt.second]) continue;
		vis[nxt.second] = 1;
		for(pll an : radj[nxt.second]){
			if(dist[an.second] + an.first == dist[nxt.second]){
				qtPaths[nxt.second] += qtPaths[an.second];
				qtPaths[nxt.second] %= MOD;
				minL[nxt.second] = min(minL[an.second] + 1, minL[nxt.second]);
				maxL[nxt.second] = max(maxL[an.second] + 1, maxL[nxt.second]);
			}
		}
		for(pll v : adj[nxt.second]){
			if(dist[v.second] > dist[nxt.second] + v.first){
				dist[v.second] = dist[nxt.second] + v.first;
				pq.push({dist[v.second],v.second});
			}
		}
	}
	cout << dist[n] << " " << qtPaths[n] << " " << minL[n] << " " << maxL[n] << "\n";

	return 0;
}