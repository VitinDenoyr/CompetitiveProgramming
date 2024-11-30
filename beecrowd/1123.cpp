#include <bits/stdc++.h>
using namespace std;
#define MAXN 250
#define pii pair<int,int>
#define INF 9999999

int main(){
	int n,m,origem,destino;
    while(cin >> n >> m >> destino >> origem && n+m+destino+origem != 0){
		int cost[MAXN][MAXN];
		vector<int> viz[MAXN], dist(MAXN,INF);
		bool visited[MAXN] = {0};
		destino--; dist[origem] = 0;

        for(int l = 0; l < m; l++){ //Leitura do Grafo
            int u,v,p;
            cin >> u >> v >> p;
            cost[u][v] = p; cost[v][u] = p;
            viz[u].push_back(v); viz[v].push_back(u);
        }

		priority_queue<pii,vector<pii>,greater<pii>> val;
		val.push({0,origem});
		while(!visited[destino]){
			int menor = val.top().second; val.pop();
			for(int vz : viz[menor]){
				bool extraCond = (menor > destino || vz-menor == 1); //Se substituir essa linha por "true", o problema vira um dijkstra padrão
				if(!visited[vz] && dist[vz] > dist[menor]+cost[menor][vz] && extraCond){
					dist[vz] = dist[menor]+cost[menor][vz];
					val.push({dist[vz],vz});
				}
			}
			visited[menor] = true;
		}
		cout << dist[destino] << "\n";
    }

	return 0;
}