#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define MAXN 100005
#define INF 10000000000000001

ll n,m, a,b,c;
vector<pii> adj[MAXN];
ll dist[MAXN] = {0};
bool vis[MAXN];

int main(){

	cin >> n >> m;
	for(ll i = 0; i < m; i++){
		cin >> a >> b >> c;
		adj[a].push_back({c,b});
	}
	for(ll i = 2; i <= n; i++){
		dist[i] = INF;
	}
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,1});
	while(!pq.empty()){
		pii at = pq.top(); pq.pop();
		if(vis[at.second]) continue;
		for(pii viz : adj[at.second]){
			if(vis[viz.second]) continue;
			if(dist[viz.second] > dist[at.second] + viz.first){
				dist[viz.second] = dist[at.second] + viz.first;
				pq.push({dist[viz.second], viz.second});
			}
		}
		vis[at.second] = true;
	}
	for(ll i = 1; i < n; i++){
		cout << dist[i] << " ";
	}
	cout << dist[n] << "\n";


	return 0;
}