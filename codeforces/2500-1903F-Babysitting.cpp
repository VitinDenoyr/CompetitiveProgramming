//https://codeforces.com/contest/1903/problem/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,m,val;
int ind,compInd,minUnvis,maxUnvis;
vector<vector<int>> adj, radj;
vector<int> vis, ord, comp;

void dfs(int k){
	vis[k] = ind;
	while(vis[minUnvis]) minUnvis++;
	while(vis[maxUnvis]) maxUnvis--;
	//Vértices do tipo "não escolhe"
	if(k > n){
		for(int u : adj[k]){
			if(!vis[u]) dfs(u);
		}
	//Vértices do tipo "escolhe"
	} else {
		for(int u = max(k-val+n,minUnvis); u <= min(k+val+n,maxUnvis); u++){ //Vértices inválidos nesse val
			if(!vis[u] && u != (k+n)) dfs(u);
		}
	}
	ord.push_back(k);
}

void findComp(int k){
	comp[k] = compInd;
	while(comp[minUnvis]) minUnvis++;
	while(comp[maxUnvis]) maxUnvis--;
	if(k <= n){ //Veio de um adj normal
		for(int u : radj[k]){
			if(comp[u] == 0) findComp(u);
		}
	} else {
		for(int u = max(k-val-n,minUnvis); u <= min(k+val-n,maxUnvis); u++){ //Nenhum vizinho de distância val ou menos é válido
			if(comp[u] == 0 && u != (k-n)) findComp(u);
		}
	}
}

void solve(){
	cin >> n >> m;
	adj = vector<vector<int>> (2*n + 1, vector<int>());
	radj = vector<vector<int>> (2*n + 1, vector<int>());

	//Leitura das arestas padrão
	for(int i = 1; i <= m; i++){
		int a,b; cin >> a >> b;
		adj[a+n].push_back(b);
		adj[b+n].push_back(a);
		radj[b].push_back(a+n);
		radj[a].push_back(b+n);
	}

	int l = 1, r = n;
	while(l < r){
		val = (l+r+1)/2 - 1;
		vis = vector<int>(2*n + 1, 0); ind = 0; compInd = 0; ord.clear();
		minUnvis = n+1; maxUnvis = 2*n;

		//Tenta fazer a DFS
		for(int i = 1; i <= 2*n; i++){
			if(!vis[i]){
				ind++;
				dfs(i);
			}
		}

		minUnvis = 1; maxUnvis = n;
		compInd = 0; comp = vector<int> (2*n+1, 0);
		
		//Associa os componentes
		for(int i = 2*n-1; i >= 0; i--){
			if(comp[ord[i]] == 0){
				compInd++;
				findComp(ord[i]);
			}
		}
		bool skip = false;
		for(int i = 1; i <= n; i++){
			if(comp[i] == comp[n+i]){
				r = val;
				skip = true;
				break;
			}
		}
		if(skip) continue;
		l = (l+r+1)/2;
	}
	cout << l << "\n";
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) solve();

	return 0;
}