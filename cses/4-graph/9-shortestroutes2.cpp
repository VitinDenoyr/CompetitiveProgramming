#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define MAXN 505
#define INF 10000000000000001

ll n,m,q, a,b,c;
vector<pii> adj[MAXN];
ll dist[MAXN][MAXN] = {0};
bool vis[MAXN][MAXN];

int main(){

	cin >> n >> m >> q;

	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			dist[i][j] = INF;
			if(i == j) dist[i][j] = 0;
		}
	}

	for(ll i = 0; i < m; i++){
		cin >> a >> b >> c;
		adj[a].push_back({c,b});
		adj[b].push_back({c,a});
		dist[a][b] = min(dist[a][b],c); dist[b][a] = min(dist[b][a],c);
	}

	for(int s = 1; s <= n; s++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dist[i][j] = min(dist[i][j], dist[i][s]+dist[s][j]);
			}
		}
	}
	for(int i = 0; i < q; i++){
		cin >> a >> b;
		if(dist[a][b] == INF) dist[a][b] = -1;
		cout << dist[a][b] << "\n";
	}

	return 0;
}