#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int n;
vector<int> parent, vis;
vector<vector<int>> adj;

int main(){

	cin >> n;
	adj = vector<vector<int>> (n+1, vector<int>());
	vis = vector<int> (n+1, 0);

	for(int i = 1; i < n; i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	//Encontra uma extremidade do diâmetro
	queue<int> q; q.push(1);
	int x0; vis[1] = 1;
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int u : adj[x]){
			if(!vis[u]){
				vis[u] = 1;
				q.push(u);
			}
		}
		x0 = x;
	}

	//Com base nela, encontra a outra enquanto calcula a distância
	queue<pii> qp; qp.push({x0,0});
	pii xn; vis[x0] = 2;
	while(!qp.empty()){
		pii x = qp.front(); qp.pop();
		for(int u : adj[x.first]){
			if(vis[u] < 2){
				vis[u] = 2;
				qp.push({u,x.second+1});
			}
		}
		xn = x;
	}

	//Imprime a distância = comprimento do diâmetro
	cout << xn.second << "\n";


	return 0;
}