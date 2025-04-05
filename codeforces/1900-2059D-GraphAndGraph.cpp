//https://codeforces.com/contest/2059/problem/D
#include <bits/stdc++.h>
#include <array>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int INF = 1000000007;

void solve(){

	int n, s1, s2; cin >> n >> s1 >> s2;
	vector<vector<int>> adj1 (n+1, vector<int> (n+1, 0)), adj2 (n+1, vector<int> (n+1, 0));
	vector<vector<int>> adjA (n+1, vector<int>()), adjB (n+1, vector<int>());

	int m1; cin >> m1;
	for(int i = 1; i <= m1; i++){
		int x,y; cin >> x >> y;
		adj1[x][y] = 1;
		adj1[y][x] = 1;
		adjA[x].push_back(y);
		adjA[y].push_back(x);
	}
	int m2; cin >> m2;
	for(int i = 1; i <= m2; i++){
		int x,y; cin >> x >> y;
		adj2[x][y] = 1;
		adj2[y][x] = 1;
		adjB[x].push_back(y);
		adjB[y].push_back(x);
	}

	for(int i = 1; i <= n; i++){
		for(int j : adjA[i]){
			if(adj2[i][j]){
				adj1[i][i] = 2; adj1[j][j] = 2;
				adj2[i][i] = 2; adj2[j][j] = 2;
			}
		}
	}

	vector<vector<int>> dist (n+1, vector<int>(n+1, INF)); dist[s1][s2] = 0;
	priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
	array<int,3> arz = {0, s1, s2}; pq.push(arz);
	while(!pq.empty()){
		array<int,3> nx = pq.top(); pq.pop();
		if(dist[nx[1]][nx[2]] < nx[0]) continue;
		for(int u : adjA[nx[1]]){
			for(int v : adjB[nx[2]]){
				if(dist[u][v] <= nx[0]+abs(u-v)) continue;
				dist[u][v] = nx[0]+abs(u-v);
				pq.push({nx[0]+abs(u-v),u,v});
			}
		}
	}

	int resp = -1;
	for(int i = 1; i <= n; i++){
		if(adj1[i][i] && dist[i][i] < dist[0][0]){
			if(resp == -1){
				resp = dist[i][i];
			} else {
				resp = min(resp, dist[i][i]);
			}
		}
	}
	cout << resp << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}