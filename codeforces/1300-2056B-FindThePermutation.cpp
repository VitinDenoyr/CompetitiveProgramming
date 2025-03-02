//https://codeforces.com/problemset/problem/2056/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<vector<char>> adj (n+1, vector<char>(n+1, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> adj[i][j];
		}
	}
	vector<int> pos (n+1, 0);

	for(int i = 1; i <= n; i++){
		int j = 1;
		for(j = 1; j < i; j++){
			if(adj[i][pos[j]] == '0'){
				break;
			}
		}
		if(j > i-1){
			pos[j] = i;
		} else {
			int aux, hold = i;
			for(int p = j; p <= i; p++){
				aux = pos[p];
				pos[p] = hold;
				hold = aux;
			}
		}
	}

	for(int i = 1; i <= n; i++){
		cout << pos[i] << " \n"[i == n];
	}

}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}