#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	int n,q; cin >> n >> q;
	vector<vector<int>> parent (n+1, vector<int>(21, 1));
	vector<vector<int>> adj (n+1, vector<int>());

	for(int i = 2; i <= n; i++){
		cin >> parent[i][0];
		adj[i].push_back({parent[i][0]});
		adj[parent[i][0]].push_back(i);
	}

	for(int j = 1; j <= 20; j++){
		for(int i = 1; i <= n; i++){
			parent[i][j] = parent[parent[i][j-1]][j-1];
		}
	}

	function<int(int,int)> lca, level;
	vector<int> lvl (n+1, -1);

	level = [&](int a, int l){
		lvl[a] = l;
		for(int u : adj[a]){
			if(lvl[u] == -1){
				level(u,l+1);
			}
		}
		return 0;
	};

	level(1,0);

	lca = [&](int a, int b){

		if(lvl[a] < lvl[b]) swap(a,b);
		int subi = lvl[a]-lvl[b];
		for(int x = 0; (1<<x) <= subi; x++){
			if(((1<<x)&subi) != 0){
				a = parent[a][x];
			}
		}

		if(a == b) return a;

		for(int it = 19; it >= 0; it--){
			if(parent[a][it] != parent[b][it]){
				a = parent[a][it];
				b = parent[b][it];
			}
		}
		return parent[a][0];
	};

	for(int iq = 1; iq <= q; iq++){
		int xi, yi; cin >> xi >> yi;
		cout << lca(xi,yi) << "\n";
	}

	return 0;
}