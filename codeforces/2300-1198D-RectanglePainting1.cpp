//https://codeforces.com/problemset/problem/1198/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	int n; cin >> n;
	vector<vector<char>> t(n, vector<char>(n,'.'));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> t[i][j];
		}
	}
	int dp[n][n][n][n] = {0};

	for(int w = 1; w <= n; w++){
		for(int h = 1; h <= n; h++){
			for(int i = 0; i <= n-w; i++){
				for(int j = 0; j <= n-h; j++){
					if(w == 1 && h == 1){
						dp[i][j][w][h] = (t[i][j] == '#');
					} else {
						dp[i][j][w][h] = max(w,h);
						for(int k = 1; k <= w-1; k++){
							dp[i][j][w][h] = min(dp[i][j][w][h], dp[i][j][k][h]+dp[i+k][j][w-k][h]);
						}
						for(int k = 1; k <= h-1; k++){
							dp[i][j][w][h] = min(dp[i][j][w][h], dp[i][j][w][k]+dp[i][j+k][w][h-k]);
						}
					}
					//cout << i << "," << j << " de [" << w << "," << h << "] = " << dp[i][j][w][h] << "\n";
				}
			}
		}
	}
	cout << dp[0][0][n][n] << "\n";

	return 0;
}