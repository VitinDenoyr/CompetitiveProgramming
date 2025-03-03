//https://codeforces.com/problemset/problem/2065/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<int> a (n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	vector<vector<int>> adj (n+1, vector<int>());
	for(int i = 1; i < n; i++){
		int u,v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> works (n+1, 0);
	for(int i = 1; i <= n; i++){
		map<int,int> qt;
		for(int u : adj[i]){
			if(a[i] == a[u]){
				works[a[i]] = 1;
			}
			qt[a[u]]++;
			if(qt[a[u]] > 1){
				works[a[u]] = 1;
			}
		}
	}

	for(int i = 1; i < n; i++){
		if(works[i]){
			cout << "1";
		} else {
			cout << "0";
		}
	}
	if(works[n]){
		cout << "1\n";
	} else {
		cout << "0\n";
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