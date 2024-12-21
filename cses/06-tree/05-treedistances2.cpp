#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>

int n; ll sum = 0;
vector<int> lvl, vis, subtree;
vector<ll> dist;
vector<vector<int>> adj;

pll process(int k){ //Pares {soma das distancias até a raiz atual, quantidade de vértices}
	vis[k] = 1; pll ans = {0,1};
	for(int v : adj[k]){
		if(vis[v]) continue;
		lvl[v] = lvl[k]+1; //Marca o nível de cada vértice
		pll res = process(v);
		ans.first += res.first + res.second; //Atualiza soma das distancias até esse vértice vindo da sub-árvore
		ans.second += res.second; //Atualiza qtd de vértices na sub-árvore
	}
	subtree[k] = ans.second; //Salva qtd de vértices na sub-árvore
	return ans;
}

void answer(int k, ll tot){
	vis[k] = 2;
	dist[k] = sum + (ll)n*lvl[k] - 2ll*tot;
	for(int v : adj[k]){
		if(vis[v] == 2) continue;
		answer(v, tot + subtree[v]);
	}
}

int main(){

	cin >> n;
	adj = vector<vector<int>> (n+1, vector<int>());
	vis = vector<int> (n+1, 0); dist = vector<ll> (n+1, 0);
	lvl = vector<int> (n+1, 0); subtree = vector<int> (n+1, 0);

	for(int i = 1; i < n; i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	sum = process(1).first;
	answer(1,0);

	for(int i = 1; i <= n; i++){
		cout << dist[i] << " \n"[i == n];
	}

	return 0;
}