//https://codeforces.com/contest/2014/problem/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000000000000009ll
#define pii pair<int,int>

void solve(int tt){
	
	int n,m,h; cin >> n >> m >> h;

	//Inicialização de vetores
	vector<bool> horse (n+1, 0);
	vector<vector<ll>> dist (n+1, vector<ll>(4, INF));
	vector<vector<pii>> adj (n+1, vector<pii>());

	//Leitura dos cavalos
	for(int i = 1; i <= h; i++){
		int k; cin >> k; horse[k] = true;	
	}

	//Leitura das arestas
	for(int i = 1; i <= m; i++){
		int a,b,c; cin >> a >> b >> c;
		adj[a].push_back({c,b});
		adj[b].push_back({c,a});
	}

	//Dijkstra
	auto shortPath = [&](int st, int id)->bool{
		//Estruturas do Dijkstra
		vector<vector<bool>> vis (n+1, vector<bool>(4, 0));
		priority_queue<array<ll,3>,vector<array<ll,3>>,greater<array<ll,3>>> pq;
		
		//Um nó/vetor é dado por (Distancia, Destino, Tem Cavalo)
		pq.push({0,st,0});
		while(!pq.empty()){
			auto [dis, des, hor] = pq.top(); pq.pop();
			int t = id*2 + hor; // Essa pessoa nesse transporte
			if(vis[des][t]) continue;

			//Distância definitiva
			vis[des][t] = 1;
			dist[des][t] = dis;

			//Calcula todas as ações possíveis de serem feitas: A pé -> A pé, A pé -> Cavalo, Cavalo -> Cavalo
			for(pii u : adj[des]){
				//Manter o meio de transporte
				ll travelCost = (hor ? u.first/2 : u.first);
				if(!vis[u.second][t] && (dist[u.second][t] > dist[des][t] + travelCost)){
					pq.push({dist[des][t] + travelCost, u.second, hor});
				}

				//Mudar de a pé para cavalo: tem que existir um cavalo, chegar a pé no lugar anterior e o destino a cavalo não pode estar visitado
				bool condition = horse[des] && (!hor) && !vis[u.second][2*id+1];
				if(condition && (dist[u.second][2*id+1] > dist[des][2*id] + u.first/2)){
					pq.push({dist[des][2*id] + u.first/2, u.second, 1});
				}
			}
		}
		return vis[n+1-st][2*id];
	};

	bool canReachHer = shortPath(1,0);
	if(!canReachHer){
		cout << -1 << "\n";
		return;
	} else {
		shortPath(n,1);
		ll bestPoint = INF;
		for(int i = 1; i <= n; i++){
			ll minA = min(dist[i][0],dist[i][1]), minB = min(dist[i][2],dist[i][3]);
			if(max(minA,minB) < bestPoint){
				bestPoint = max(minA,minB);
			}
		}
		cout << bestPoint << "\n";
	}
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t; cin >> t;
	while(t--){
		solve(t);
	}
 
	return 0;
}