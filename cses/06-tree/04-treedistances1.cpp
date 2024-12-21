#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int n;
vector<int> parent, vis, dist, dist2;
vector<vector<int>> adj;

int main(){

	cin >> n;
	adj = vector<vector<int>> (n+1, vector<int>());
	vis = vector<int> (n+1, 0); dist = vector<int> (n+1, 0);
	dist2 = vector<int> (n+1, 0);

	for(int i = 1; i < n; i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	//Encontra o diâmetro e guarda os extremos em x0 e xn
	queue<int> q; q.push(1);
	int x0; vis[1] = 1;
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int u : adj[x]){
			if(!vis[u]){
				vis[u] = 1;
				q.push(u);
			}
		}
		x0 = x;
	}

	queue<pii> qp; qp.push({x0,0});
	pii xn; vis[x0] = 2;
	while(!qp.empty()){
		pii x = qp.front(); qp.pop();
		for(int u : adj[x.first]){
			if(vis[u] < 2){
				vis[u] = 2;
				dist[u] = x.second+1;
				qp.push({u,x.second+1});
			}
		}
		xn = x;
	}
	
	//Agora calcula as distancias de xn
	qp.push({xn.first,0}); vis[xn.first] = 3;
	while(!qp.empty()){
		pii x = qp.front(); qp.pop();
		for(int u : adj[x.first]){
			if(vis[u] < 3){
				vis[u] = 3;
				dist2[u] = x.second+1;
				qp.push({u,x.second+1});
			}
		}
	}

	for(int i = 1; i <= n; i++){
		cout << max(dist[i],dist2[i]) << " \n"[i == n];
	}

	return 0;
}