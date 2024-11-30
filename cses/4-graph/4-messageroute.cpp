#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100002

int n, m;
vector<int> adj[MAXN];
int vis[MAXN], prv[MAXN];

queue<int> q;
void bfs(int a){
	vis[a] = 1;
	q.push(a);
	while(!q.empty() && !vis[n]){
		a = q.front(); q.pop();
		for(int v : adj[a]){
			if(!vis[v]){
				vis[v] = 1;
				prv[v] = a;
				q.push(v);
			}
		}
	}
}

void construct(int a){
	vector<int> lis = {a};
	while(a != 1){
		a = prv[a];
		lis.push_back(a);
	}
	cout << lis.size() << "\n";
	for(int j = lis.size()-1; j > 0; j--){
		cout << lis[j] << " ";
	}
	cout << lis[0] << "\n";
}

int main(){

	cin >> n >> m;
	for(int i = 0; i < m; i ++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bfs(1);
	if(vis[n]){
		construct(n);
	} else {
		cout << "IMPOSSIBLE\n";
	}
	

	return 0;
}