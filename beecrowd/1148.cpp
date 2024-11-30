#include <bits/stdc++.h>
using namespace std;
#define MAXN 501
#define MAXE 251001
#define INF 9999999
#define pii pair<int,int>

int dist[MAXN][MAXN];
vector<int> viz[MAXN];

int main() {
    int n,env,cons;
    while(cin >> n >> env && (n+env > 0)){
		memset(dist,0,sizeof(dist));
		memset(viz,0,sizeof(viz));
        
        for(int i = 0; i < env; i++){
            int a,b,t;
            cin >> a >> b >> t;
            dist[a][b] = t;
			if(dist[b][a] > 0){
				dist[a][b] = 0;
				dist[b][a] = 0;
			}
			viz[a].push_back(b);
        }

        cin >> cons;
        for(int i = 0; i < cons; i++){
			vector<int> cost (MAXN, INF);
			bool visit[MAXN] = {0};
            int a,b;
            cin >> a >> b;
			cost[a] = 0;

			priority_queue<pii,vector<pii>,greater<pii>> next;
			next.push({0,a});
			while(!visit[b]){
				if(next.size() == 0) break;
				int current = next.top().second; next.pop();
				if(visit[current]) continue;
				for(int v : viz[current]){
					if(cost[v] > dist[current][v] + cost[current]){ //Novo menor caminho
						cost[v] = dist[current][v] + cost[current];
						next.push({cost[v],v});
					}
				}
				visit[current] = true;
			}
			if(cost[b] < INF){
				cout << cost[b] << "\n";
			} else {
				cout << "Nao e possivel entregar a carta\n";
			}
        }
		cout << "\n";
    }
 
    return 0;
}