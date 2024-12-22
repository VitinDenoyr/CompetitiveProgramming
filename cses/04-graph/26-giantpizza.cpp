#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int n,m;
vector<vector<int>> adj, radj;
vector<int> comp, vis, ord;

void dfs(int k){
	vis[k] = 1;
	for(int u : adj[k]){
		if(!vis[u]) dfs(u);
	}
	ord.push_back(k);
}

void findComp(int k, int c){
	comp[k] = c;
	for(int u : radj[k]){
		if(comp[u] == 0) findComp(u,c);
	}
}

int main(){

	cin >> m >> n;
	adj = vector<vector<int>>(2*n+1, vector<int>()); radj = vector<vector<int>>(2*n+1, vector<int>());
	vis = vector<int> (2*n+1, 0); comp = vector<int> (2*n+1, 0); 

	//Leitura da entrada e interpretação como um grafo
	for(int i = 1; i <= m; i++){
		int a,b; char c,d;
		cin >> c >> a >> d >> b;
		adj[a+n*(c == '+')].push_back(b+n*(d == '-'));
		adj[b+n*(d == '+')].push_back(a+n*(c == '-'));
		radj[b+n*(d == '-')].push_back(a+n*(c == '+'));
		radj[a+n*(c == '-')].push_back(b+n*(d == '+'));
	}

	//Processa na ordem de visitação
	for(int i = 1; i <= 2*n; i++){
		if(!vis[i]) dfs(i);
	}

	//Na ordem inversa de visitação, associa os componentes
	int qtComponents = 0;
	for(int i = 2*n-1; i >= 0; i--){
		if(comp[ord[i]] == 0) findComp(ord[i],++qtComponents);
	}

	//Decide se tem vértices opostos na mesma componente. Se tiver, encerra.
	//Se não tiver, apenas escolhe qual valor foi percorrido depois na ordem topológica (que é equivalente ao número da componente ser maior).
	string ans = "";
	for(int i = 1; i <= n; i++){
		if(comp[i] == comp[i+n]){
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		ans += (comp[i] > comp[i+n] ? "+" : "-");
		ans += " \n"[i == n];
	}
	cout << ans;

	return 0;
}