//https://codeforces.com/contest/2014/problem/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pip pair<ll,pair<int,int>>
#define INF 100000000000000009ll
#define IND second.first
#define TYP second.second
 
int n,m,h;
vector<bool> horse;
vector<vector<pii>> adj;
 
bool shortPath(vector<ll>& dist, vector<ll>& distH, int start, ll distCav){
	priority_queue<pip,vector<pip>,greater<pip>> pq;
	vector<int> vis (n+1, 0), visH (n+1, 0);
	pq.push({0,{start,0}}); dist[start] = 0;
 
	while(!pq.empty()){
		pip vert = pq.top(); pq.pop();
		if((vert.TYP && (distH[vert.IND] != vert.first)) || (!vert.TYP && (dist[vert.IND] != vert.first))) continue;
		if(vert.TYP == 0){
			vis[vert.IND] = true;
		} else {
			visH[vert.IND] = true;
		}
		for(pii vz : adj[vert.IND]){
			if(!vis[vz.second]){
				if(dist[vert.IND] + vz.first < dist[vz.second]){
					dist[vz.second] = dist[vert.IND] + vz.first;
					pq.push({dist[vz.second],{vz.second,0}});
				}
			}
			if(!visH[vz.second]){
				if(distH[vert.IND] + vz.first/2 < distH[vz.second]){
					distH[vz.second] = distH[vert.IND] + vz.first/2;
					pq.push({distH[vz.second],{vz.second,1}});
				}
				if(horse[vert.IND] && (dist[vert.IND] + vz.first/2 < distH[vz.second])){
					distH[vz.second] = dist[vert.IND] + vz.first/2;
					pq.push({distH[vz.second],{vz.second,1}});
				}
			}
		}
	}
 
	if(!vis[n+1 - start]) return false;
	return true;
}
 
int main(){
 
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--){
		cin >> n >> m >> h;
		horse = vector<bool> (n+1,0);
		vector<ll> distA (n+1, INF), distB (n+1, INF);
		vector<ll> distHA (n+1, INF), distHB (n+1, INF);
		ll distCavA = INF, distCavB = INF;
		adj = vector<vector<pii>> (n+1, vector<pii>());
		for(int i = 1; i <= h; i++){
			int vi; cin >> vi; horse[vi] = true;
		}
		for(int i = 1; i <= m; i++){
			int a,b,c; cin >> a >> b >> c;
			adj[a].push_back({c,b});
			adj[b].push_back({c,a});
		}
		bool reach = shortPath(distA,distHA,1,distCavA);
		if(!reach){
			cout << -1 << "\n";
		} else {
			shortPath(distB,distHB,n,distCavB);
			ll minDist = INF;
			for(int i = 1; i <= n; i++){
				ll minA = min(distA[i],distHA[i]), minB = min(distB[i],distHB[i]);
				if(max(minA,minB) < minDist){
					minDist = max(minA,minB);
				}
			}
			cout << minDist << "\n";
		}
	}
 
	return 0;
}