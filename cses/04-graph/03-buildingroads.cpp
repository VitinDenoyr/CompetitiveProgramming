#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100002
#define pii pair<int,int>

int n, m;
vector<int> adj[MAXN];
bool pertence[MAXN];
vector<pii> roads;

void dfs(int k){
	if(pertence[k]) return;
	pertence[k] = true;
	for(auto vz : adj[k]){
		dfs(vz);
	}
}

int main(){

	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int it = 1;
	while(it <= n){
		if(pertence[it]){
			it++;
		} else {
			if(it > 1) roads.push_back({it-1,it});
			dfs(it);
		}
	}
	cout << roads.size() << "\n";
	for(pii p : roads){
		cout << p.first << " " << p.second << "\n";
	}

	return 0;
}