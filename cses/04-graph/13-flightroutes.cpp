#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define MAXN 100005

ll n,m,k;
vector<pll> adj[MAXN];
priority_queue<pll,vector<pll>,less<pll>> pq[MAXN]; //Guarda os caminhos em fila de prioridade com a posição dele tb
vector<ll> paths[MAXN]; //Guarda os caminhos em vetor
priority_queue<pll,vector<pll>,greater<pll>> order; //Ordem dos vértices a receberem caminho definitivo
bool vis[MAXN][10];

int main(){

	cin >> n >> m >> k;
	for(ll i = 0; i < m; i++){
		ll a,b,c;
		cin >> a >> b >> c;
		adj[a].push_back({c,b});
	}
	paths[1].push_back(0); pq[1].push({0,paths[1].size()-1}); 
	order.push({0,1});
	while(!order.empty()){
		pll next = order.top(); order.pop();
		//if(vis[next.second]) continue;
		//vis[next.second] = true;
		for(int pind = 0; pind < paths[next.second].size(); pind++){ //Pra cada caminho:
			ll p = paths[next.second][pind];
			if(vis[next.second][pind]) continue; //Caminho já visto
			
			for(pll viz : adj[next.second]){ //Pra cada vizinho:sto
				//Vê se o caminho de agora entra no top "k" caminhos
				if(pq[viz.second].size() < k || p + viz.first < pq[viz.second].top().first){
					//Se sim:
					if(pq[viz.second].size() == k){ //Substituição
						pll old = pq[viz.second].top(); pq[viz.second].pop();
						paths[viz.second][old.second] = p + viz.first; //novo cara do top
						pq[viz.second].push({p + viz.first,old.second}); //atualiza a pq
						order.push({paths[viz.second][old.second],viz.second});
						vis[next.second][pind] = false; //agora esse caminho é outro, então não visitei ele ainda
					} else {
						paths[viz.second].push_back(p + viz.first);
						pq[viz.second].push({p + viz.first, paths[viz.second].size()-1});
						order.push({p + viz.first,viz.second});
					}
				}
			}
			vis[next.second][pind] = true;
		}
	}
	//Agora que terminamos:
	vector<ll> res = paths[n];
	sort(res.begin(), res.end());
	for(int i = 0; i < res.size()-1; i++){
		cout << res[i] << " ";
	}
	cout << res[res.size()-1] << "\n";
	
	return 0;
}


/*
Menor distancia ao inicio é 0, as outras é infinito;
de 0 posso ir até as arestas e alterar o menor caminho;
dado esse processo, quem tem o menor caminho agora é definitivo, então visita ele;
esse processo se repete. Se em algum momento eu alterar o menor caminho de alguém, ao invés de alterar, eu vou ver se tem menos de D. Se tiver, eu adiciono como um dos caminhos, se já tiver D, eu só adiciono se for melhor que o pior caminho, pq significa que esse novo caminho ta no top D caminhos. Eu não comparo só com o melhor caminho do vértice atual, e sim com todos.
Repetir esse processo dá a resposta
*/