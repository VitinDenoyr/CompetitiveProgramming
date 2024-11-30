#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

vector<vector<int>> adj, adj2;
vector<int> deg, owned;

int main(){

	int n,m; cin >> n >> m;
	adj = vector<vector<int>> (n+1, vector<int>());
	//adj2 = vector<vector<int>> (n+1, vector<int>());
	owned = vector<int> (n+1, 0);
	deg = vector<int> (n+1, 0);
	//map<pii,bool> edges;

	for(int i = 1; i <= m; i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		//edges[{min(a,b),max(a,b)}] = 1;
		deg[a]++; deg[b]++;
	}

	for(int i = 1; i <= n; i++){
		if(deg[i]%2 == 1){
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}

	vector<vector<int>> cycles;
	int qtEdges = 0, vert = 1;
	while(qtEdges < m){
		while(deg[vert] == 0) vert = (vert%n)+1;
		//Vértice atual tem ao menos 2 arestas faltando
		vector<int> cyc; cyc.push_back(vert);
		
		

		
	}


	return 0;
}