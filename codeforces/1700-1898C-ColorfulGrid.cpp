#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

char rev(char c){
	if(c == 'R'){
		return 'B';
	}
	return 'R';
}

void solve(){

	int n,m,k; cin >> n >> m >> k;
	
	int r = (m+n)%2;

	if(k%2 != r || k < (m+n-2)){
		cout << "NO\n";
		return;
	} else {
		cout << "YES\n";
		vector<vector<char>> v (m+1, vector<char>(n+1, 'B'));
		vector<vector<char>> h (n+1, vector<char>(m+1, 'R'));
		for(int i = 2; i <= n-1; i++){
			v[1][i] = rev(v[1][i-1]);
		}
		h[n][1] = rev(v[1][n-1]);
		for(int i = 2; i <= m-1; i++){
			h[n][i] = rev(h[n][i-1]);
		}
		v[2][1] = rev(v[1][1]);
		h[1][1] = v[1][1];
		h[2][1] = h[1][1];
		v[m][n-1] = rev(h[n][m-1]);
		v[m-1][n-1] = v[m][n-1];
		h[n-1][m-1] = h[n][m-1];

		for(int i = 1; i <= n; i++){
			for(int j = 1; j < m; j++){
				cout << h[i][j] << " \n"[j==(m-1)];
			}
		}
		for(int i = 1; i < n; i++){
			for(int j = 1; j <= m; j++){
				cout << v[j][i] << " \n"[j==(m)];
			}
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