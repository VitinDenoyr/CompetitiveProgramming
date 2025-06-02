//https://codeforces.com/problemset/problem/1198/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vvvvi vector<vector<vector<vector<int>>>>

int main(){

	int n; cin >> n;
	vector<vector<int>> a (n+1, vector<int> (n+1, 0));
	for(int i = 1; i <= n; i++){
		string st; cin >> st;
		for(int j = 1; j <= n; j++){
			if(st[j-1] == '#'){
				a[i][j] = 1;
			}
		}
	}

	vvvvi dp (n+2, vvvi (n+2, vvi (n+2, vi (n+2, 0))));

	for(int w = 1; w <= n; w++){
		for(int h = 1; h <= n; h++){
			for(int x = 1; x+w-1 <= n; x++){
				for(int y = 1; y+h-1 <= n; y++){
					if(w == h && w == 1){
						dp[x][y][w][h] = a[x][y];
					} else {
						dp[x][y][w][h] = max(w,h);
						for(int p = 1; p < h; p++){
							dp[x][y][w][h] = min(dp[x][y][w][h], dp[x][y][w][p] + dp[x][y+p][w][h-p]);
						}
						for(int q = 1; q < w; q++){
							dp[x][y][w][h] = min(dp[x][y][w][h], dp[x][y][q][h] + dp[x+q][y][w-q][h]);
						}
					}
				}
			}
		}
	}

	cout << dp[1][1][n][n] << "\n";
	
	return 0;

}