#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100002

int n,m;
vector<int> adj[MAXN];
int team[MAXN];
int vis[MAXN];

queue<int> q;

bool bfs(int a){
	vis[a] = 1;
	team[a] = 1;
	q.push(a);
	while(!q.empty()){
		a = q.front(); q.pop();
		for(int v : adj[a]){
			if(!vis[v]){
				vis[v] = 1;
				team[v] = 3 - team[a];
				q.push(v);
			} else if(team[v] == team[a]) return false;
		}
	}
	return true;
}

int main(){

	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bool possible = true;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			bool res = bfs(i);
			if(!res){
				possible = false;
				break;
			}
		}
	}
	if(possible){
		for(int i = 1; i < n; i++){
			cout << team[i] << " ";
		}
		cout << team[n] << "\n";
	} else {
		cout << "IMPOSSIBLE\n";
	}
	

	return 0;
}