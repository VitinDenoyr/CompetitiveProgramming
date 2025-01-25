//https://codeforces.com/problemset/problem/2060/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){

	int n, m; cin >> n >> m;

	map<int,int> of;
	vector<bool> played (n+1, 0);
	vector<vector<int>> cow (n+1, vector<int>(m+1, 0));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> cow[i][j];
			of[cow[i][j]] = i;
		}
	}

	vector<int> p (n+1, 0);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			int card = i*n + j;
			if(of[j] != of[card]){
				cout << -1 << "\n";
				return;
			}
		}
	}
	for(int j = 0; j < n; j++){
		cout << of[j] << " \n"[j == n-1];
	}
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}