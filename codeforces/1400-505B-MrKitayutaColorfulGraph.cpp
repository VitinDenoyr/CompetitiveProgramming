//https://codeforces.com/problemset/problem/505/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool can = false;
vector<bool> vis;
vector<vector<vector<int>>> adj;
void dfs(int a, int b, int color){
	vis[a] = true; if(a == b) can = true;
	for(int vz : adj[color][a]){
		if(!vis[vz]) dfs(vz,b,color);
	}
}

int main(){

	int n,m; cin >> n >> m;
	adj = vector<vector<vector<int>>> (m+1, vector<vector<int>>(n+1, vector<int>()));
	for(int i = 0; i < m; i++){
		int a,b,c;
		cin >> a >> b >> c;
		adj[c][a].push_back(b);
		adj[c][b].push_back(a);
	}
	int q; cin >> q;
	for(int i = 0; i < q; i++){
		int u,v;
		cin >> u >> v;
		int qtd = 0;
		for(int cor = 1; cor <= m; cor++){
			vis = vector<bool>(n+1,0);
			can = false;
			dfs(u,v,cor);
			if(can) qtd++;
		}
		cout << qtd << "\n";
	}

	return 0;
}