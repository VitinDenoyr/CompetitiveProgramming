#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100002
 
int n,m;
vector<int> adj[MAXN];
vector<int> pathway;
bool vis[MAXN], met[MAXN];
 
int dfs(int a){
	met[a] = 1; vis[a] = 1;
	for(int v : adj[a]){
		if(vis[v]){
			pathway.push_back(v);
			pathway.push_back(a);
			return 1;
		} else if(!met[v]){
			bool found = dfs(v);
			if(found){
				if(pathway[0] != pathway[pathway.size()-1]){
					pathway.push_back(a);
				}
				return 1;
			}
		}
	}
	vis[a] = 0;
	return 0;
}
 
int main(){
 
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	bool ans;
	for(int i = 1; i <= n; i++){
		if(met[i]) continue;
		ans = dfs(i);
		if(ans) break;
	}
	if(ans){
		cout << pathway.size() << "\n";
		for(int j = pathway.size()-1; j > 0; j--){
			cout << pathway[j] << " ";
		}
		cout << pathway[0] << "\n";
	} else {
		cout << "IMPOSSIBLE\n";
	}
 
	return 0;
}