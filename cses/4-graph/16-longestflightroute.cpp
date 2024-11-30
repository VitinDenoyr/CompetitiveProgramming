#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
 
int n,m;
vector<int> adj[MAXN];
bool met[MAXN]; int nxt[MAXN], siz[MAXN];
 
void dfs(int a){
	for(int v : adj[a]){
		if(met[v]){
			if(siz[a] < siz[v]+1){
				siz[a] = siz[v]+1;
				nxt[a] = v;
			}
		} else {
			dfs(v);
			if(siz[a] < siz[v]+1){
				siz[a] = siz[v]+1;
				nxt[a] = v;
			}
		}
	}
	met[a] = true;
	if(siz[a] == 0) siz[a] = -1;
}
 
int main(){
 
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	siz[n] = 1; met[n] = 1; dfs(1);
	if(siz[1] > 0){
		cout << siz[1] << "\n";
		int at = 1;
		for(int i = 0; i < siz[1]-1; i++){
			cout << at << " ";
			at = nxt[at];
		}
		cout << at << "\n";
	} else {
		cout << "IMPOSSIBLE\n";
	}
	
 
	return 0;
}