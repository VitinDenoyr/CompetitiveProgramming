#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1002
int g[MAXN][MAXN] = {0};
bool vis[MAXN][MAXN] = {0};
int n,m;

void dfs(int a, int b){
	if(a < 0 || b < 0 || a >= n || b >= m) return;
	if(vis[a][b] || !g[a][b]) return;
	vis[a][b] = 1;
	vector<pair<int,int>> adj = {{a+1,b},{a-1,b},{a,b+1},{a,b-1}};
	for(auto vz : adj){
		dfs(vz.first,vz.second);
	}
}

int main(){

	char c; cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> c;
			if(c == '.') g[i][j] = 1;
		}
	}
	int qt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(g[i][j] && !vis[i][j]){
				dfs(i,j);
				qt++;
			}
		}
	}
	cout << qt << "\n";

	return 0;
}