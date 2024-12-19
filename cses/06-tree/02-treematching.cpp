#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

vector<vector<int>> adj;
vector<int> vis, parent, deg;

void root(int u){
	vis[u] = 1;
	for(int v : adj[u]){
		if(!vis[v]){
			parent[v] = u;
			deg[u]++;
			root(v);
		}
	}
}

int main(){

	int n; cin >> n;
	adj = vector<vector<int>> (n+1, vector<int>());
	vis = vector<int> (n+1, 0); parent = vector<int> (n+1, 0); deg = vector<int> (n+1, 0);
	deg[0] = n+2; vis[0] = 2;

	for(int i = 1; i <= n-1; i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	//Enraiza a árvore no nó 1
	root(1);

	queue<int> q;
	for(int i = 1; i <= n; i++){ //Coleta as folhas
		if(deg[i] == 0) q.push(i);
	}

	int qt = 0;
	while(!q.empty()){
		int f = q.front(); q.pop();
		if(vis[parent[f]] == 2) continue;

		vis[parent[f]] = 2; vis[f] = 2;
		deg[f] = 0; deg[parent[f]] = 0; deg[parent[parent[f]]]--;
		if(deg[parent[parent[f]]] == 0) q.push(parent[parent[f]]);
		qt++;
	}

	cout << qt << "\n";

	return 0;
}