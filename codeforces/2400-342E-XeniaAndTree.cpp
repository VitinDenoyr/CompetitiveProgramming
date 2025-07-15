//https://codeforces.com/problemset/problem/342/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n,m; cin >> n >> m;

	vector<vector<int>> adj (n+1, vector<int>());
	vector<int> color (n+1, 0);
	color[1] = 1; 
	for(int i = 1; i < n; i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 1; i <= m; i++){
		int t,v; cin >> t >> v;
		if(t == 1){

		} else {

		}
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}