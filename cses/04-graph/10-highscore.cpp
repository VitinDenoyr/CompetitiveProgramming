#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define INF 10000000000000003
#define MAXN 2505
#define MAXM 5005

/*
IDEIA GERAL - (Código nível 500 de ler)
Faz um algoritmo de belford-roxo N vezes. Se na N-esima vez aparecer alterações positivas, significa q tem algum ciclo, então faremos uma BFS em 1 para procurar os ciclos. Sempre que acharmos um ciclo, mudamos o modo da BFS para tentar encontrar, a partir desse momento, somente se é possível ir de A até N sendo A o primeiro nó desse ciclo que achamos. Se em algum desses momentos acharmos um caminho até N de um nó que sabemos que faz parte de um ciclo positivo, printa -1, caso contrário, printa dist[n] normal.
*/
 
ll n,m, a,b,c;
vector<pll> adj[MAXN];
vector<vector<ll>> ares;
ll dist[MAXN], distdfs[MAXN];
int vis[MAXN], visIt = 1;
 
int dfs(int a, int sm, int sigma){
	//cout << a << ".\n";
	if(sigma == n+1 && a == n) return n+1;
	vis[a] = visIt;
	distdfs[a] = sm;
	for(auto v : adj[a]){
		if(vis[v.first] == visIt && (sm + v.second > distdfs[v.first]) && sigma == 0){ //virou sigma com v.first
			if(v.first == a){
				visIt++;
				vis[a] = visIt;
				int s = dfs(a, sm, n+1);
				visIt--;
				if(s == n+1){
					return s;
				}
			} else {
				vis[a]--;
				return v.first;
			}
		} else if(vis[v.first] < visIt){
			if(v.first == n && sigma == n+1){ //OHHHH MAI GA
				return n+1;
			}
			int r = dfs(v.first, v.second+sm, sigma);
			if(r > 0 && r <= n && r != a){ //transformando em sigma
				vis[a]--;
				return r;
			} else if(r == a){ //se tornou um sigma completo
				visIt++;
				vis[a] = visIt;
				int s = dfs(a, sm, n+1);
				visIt--;
				if(s == n+1){
					return s;
				}
			} else if(r == n+1){
				return r;
			}
		}
	}
	vis[a]--;
	distdfs[a] = 0;
	return 0;
}
 
int main(){
 
	cin >> n >> m;
	for(int i = 2; i <= n; i++){
		dist[i] = -INF;
	}
	for(int i = 1; i <= m; i++){
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
		ares.push_back({a,b,c});
	}
	bool hasCycle = false;
	for(int r = 1; r <= n; r++){
		bool show = false;
		for(vector<ll> ar : ares){
			if(dist[ar[0]] + ar[2] > dist[ar[1]]){
				dist[ar[1]] = dist[ar[0]] + ar[2];
				show = true;
			}
		}
		if(r == n && show){
			hasCycle = true;
		}
	}
	if(hasCycle){
		int cyc = dfs(1,0,0); //0 -> sem ciclo, então é dist[n]. 
		if(cyc == n+1){
			cout << -1 << "\n";
		} else {
			cout << dist[n];
		}
	} else {
		cout << dist[n] << "\n";
	}
 
	
 
	return 0;
}