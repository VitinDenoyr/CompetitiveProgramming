#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int n,m;
vector<vector<pii>> adj;
vector<int> deg, path, vis;

void dfs(int u){
	while(deg[u] > 0){
		deg[u]--;
		int v = adj[u][deg[u]].first, ind = adj[u][deg[u]].second;
		if(vis[ind]) continue;
		vis[ind] = 1;
		dfs(v);
	}
	path.push_back(u);
}

int main(){

	cin >> n >> m;
	deg = vector<int>(n+1,0); vis = vector<int> (m+1, 0);
	adj = vector<vector<pii>>(n+1, vector<pii>());
	for(int i = 1; i <= m; i++){
		int a,b; cin >> a >> b;
		adj[a].push_back({b,i});
		adj[b].push_back({a,i});
		deg[a]++; deg[b]++;
	}

	//Verifica graus
	for(int i = 1; i <= n; i++){
		if(deg[i]%2 == 1){
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}

	//Graus estão certos, tenta achar o caminho
	dfs(1);
	if(path.size() == m+1){
		for(int i = 0; i <= m; i++){
			cout << path[i] << " \n"[i == m];
		}
	} else { //Grafo desconexo
		cout << "IMPOSSIBLE\n";
	}

	return 0;
}