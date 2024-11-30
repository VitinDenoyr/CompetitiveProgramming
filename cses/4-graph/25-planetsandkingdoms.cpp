#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define printvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl
#define MAXN 100005

int n,m;
vector<int> adj[MAXN], radj[MAXN], verts;
int vis[MAXN] = {0}, fin[MAXN] = {0};
int indexator = 0, cIndexator = 0, component[MAXN] = {0};

void dfs(int a){
	vis[a] = ++indexator;
	for(int v : adj[a]){
		if(!vis[v]){
			dfs(v);
		}
	}
	fin[a] = ++indexator;
	verts.push_back(a);
}

void build(int a){
	component[a] = cIndexator;
	for(int v : radj[a]){
		if(component[v] == 0){
			build(v);
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		radj[b].push_back(a);
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]) dfs(i);
	}
	for(int i = verts.size()-1; i >= 0; i--){
		if(component[verts[i]] == 0){
			cIndexator++;
			build(verts[i]);
		}
	}
	cout << cIndexator << "\n";
	for(int i = 1; i < n; i++){
		cout << component[i] << " ";
	}
	cout << component[n] << "\n";

	return 0;
}