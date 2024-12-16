#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

vector<int> vis, order, inits;
vector<pii> path;
vector<vector<int>> adj, radj;

void dfs(int v){
	if(vis[v]) return;
	vis[v] = 1;
	for(int u : adj[v]){
		dfs(u);
	}
	order.push_back(v);
}

void getPath(int v, int n){
	if(path[v].second > 0) getPath(path[v].second,n);
	cout << v << " \n"[v == n];
}

int main(){

	int n,m; cin >> n >> m;
	adj = vector<vector<int>> (n+1, vector<int>());
	radj = vector<vector<int>> (n+1, vector<int>());
	path = vector<pii> (n+1, {-n*5,0});
	inits = vector<int> (n+1, 1);
	vis = vector<int> (n+1, 0);

	for(int i = 1; i <= m; i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		radj[b].push_back(a);
		inits[b] = 0;
	}

	for(int i = 1; i <= n; i++){
		if(inits[i]) dfs(i);
	}

	path[1] = {1,0};
	for(int i = 0; i < n; i++){
		int u = order[n-1-i];
		for(int v : radj[u]){
			if(path[v].first >= path[u].first){
				path[u] = {path[v].first+1, v};
			}
		}
	}
	if(path[n].first <= 0){
		cout << "IMPOSSIBLE\n";
	} else {
		cout << path[n].first << "\n";
		getPath(n,n);
	}

	return 0;
}