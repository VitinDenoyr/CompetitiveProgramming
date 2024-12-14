#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const ll INF = 100000000000000000ll;

int compInd = 0;
vector<int> vis, verts, component;
vector<vector<int>> adj, radj, nadj;
vector<ll> value, benefit; vector<bool> hasBenefit;

void dfs(int v){
	vis[v] = 1;
	for(int u : adj[v]){
		if(!vis[u]){
			dfs(u);
		}
	}
	verts.push_back(v);
}

void findComponent(int v){
	component[v] = compInd;
	for(int u : radj[v]){
		if(component[u] == 0){
			findComponent(u);
		}
	}
}

ll evaluate(int v){
	if(hasBenefit[v]) return benefit[v];
	for(int u : nadj[v]){
		benefit[v] = max(evaluate(u), benefit[v]);
	}
	benefit[v] += value[v];
	hasBenefit[v] = true;
	return benefit[v];
}

int main(){

	int n,m; cin >> n >> m;
	vector<ll> coins (n+1, 0);
	adj = vector<vector<int>>(n+1, vector<int>());
	radj = vector<vector<int>>(n+1, vector<int>());
	vis = vector<int> (n+1,0); component = vector<int>(n+1,0);
	value = vector<ll>(n+1,0); benefit = vector<ll>(n+1,0);
	hasBenefit = vector<bool>(n+1,false);

	for(int i = 1; i <= n; i++){
		cin >> coins[i];
	}
	for(int i = 1; i <= m; i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		radj[b].push_back(a);
	}

	//Primeiro passo: Processar os vizinhos
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i);
		}
	}

	//Segundo passo: Acha os componentes
	for(int i = n-1; i >= 0; i--){
		if(component[verts[i]] == 0){
			compInd++;
			findComponent(verts[i]);
		}
	}

	//Terceiro passo: refaz o grafo onde componentes são vértices
	nadj = vector<vector<int>>(compInd+1, vector<int>());
	set<pii> ares; //Arestas já inclusas no grafo de componentes

	for(int i = 1; i <= n; i++){ //Arestas de cada vértice
		for(int k : adj[i]){
			if (ares.find({component[i],component[k]}) == ares.end() && component[i] != component[k]){
				ares.insert({component[i],component[k]});
				nadj[component[i]].push_back(component[k]);
			}
		}
	}

	//Quarto passo: Com o novo grafo acíclico, processa o "valor" de cada vértice novamente
	for(int i = 1; i <= n; i++){
		value[component[i]] += coins[i];
	}

	//Quinto passo: Calcula o benefício de todos os vértices
	ll resp = -INF;
	for(int i = 1; i <= compInd; i++){
		resp = max(evaluate(i), resp);
	}
	cout << resp << "\n";


	return 0;
}