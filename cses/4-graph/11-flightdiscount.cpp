#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define MAXN 100005
#define INF 100000000000000007

ll n,m;
vector<pll> adj[MAXN];
ll vis[MAXN], visIt = 1;
ll dist0[MAXN], dist1[MAXN];

int main(){

	cin >> n >> m;
	for(ll i = 0; i < m; i++){
		ll a,b,c;
		cin >> a >> b >> c;
		adj[a].push_back({c,b});
	}

	for(ll i = 2; i <= n; i++){
		dist0[i] = INF; dist1[i] = INF;
	}
	dist1[1] = INF;

	//Dijkstra sem o bilhete
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	pq.push({0,1});
	while(!pq.empty()){
		pll nxt = pq.top(); pq.pop();
		if(vis[nxt.second]) continue;
		vis[nxt.second] = visIt;
		for(auto vz : adj[nxt.second]){
			if(vis[vz.second]) continue;
			if(dist0[vz.second] > dist0[nxt.second] + vz.first){
				dist0[vz.second] = dist0[nxt.second] + vz.first;
				pq.push({dist0[vz.second], vz.second});
			}
		}
	}

	//Dijkstra com o bilhete
	visIt++;
	pq.push({0,1});
	while(!pq.empty()){
		pll nxt = pq.top(); pq.pop();
		if(vis[nxt.second] == visIt) continue;
		vis[nxt.second] = visIt;
		for(auto vz : adj[nxt.second]){
			if(vis[vz.second] == visIt) continue;
			if(dist1[vz.second] > dist0[nxt.second] + (vz.first)/2){
				dist1[vz.second] = dist0[nxt.second] + (vz.first)/2;
				pq.push({dist1[vz.second], vz.second});
			}
			if(dist1[vz.second] > dist1[nxt.second] + vz.first){
				dist1[vz.second] = dist1[nxt.second] + vz.first;
				pq.push({dist1[vz.second], vz.second});
			}
		}
	}

	cout << dist1[n] << "\n";

	return 0;
}