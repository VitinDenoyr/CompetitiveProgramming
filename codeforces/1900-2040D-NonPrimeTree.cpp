//https://codeforces.com/contest/2040/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	int n; cin >> n;
	vector<int> parent (n+1, 0), vis(n+1, 0), color(n+1, 0);
	vector<vector<int>> adj (n+1, vector<int>());

	for(int i = 1; i < n; i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	function<void(int,int)> root;
	root = [&](int r, int f = 0){
		parent[r] = f;
		color[r] = 1 - color[f];
		for(int v : adj[r]){
			if(parent[v] == 0){
				root(v,r);
			}
		}
	};
	root(1,0);

	int le = 2, ri = 2*n;

	queue<int> q; q.push(1); int last = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(color[u]){
			vis[u] = le;
			le += 2;
			last = u;
		} else {
			vis[u] = ri;
			ri -= 2;
			last = u;
		}
		for(int v : adj[u]){
			if(!vis[v]){
				vis[v] = 2*n+1;
				q.push(v);
			};
		}
	}
	vis[last] = vis[parent[last]]-1;

	for(int i = 1; i <= n; i++){
		cout << vis[i] << " \n"[i==n];
	}
}

int main(){

	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}