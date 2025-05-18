//https://codeforces.com/problemset/problem/2101/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<vector<int>> grid (n+1, vector<int>(n+1, 0));
	int nx = 1;
	function<void(int,int,int,int)> fix = [&](int x1, int y1, int xn, int yn){
		int up = y1 - 1, down = n - yn;
		int left = x1 - 1, right = n - xn;
		if(up == left && down == right && up == right && up == 0) return;
		if(right >= left && right >= up && right >= down){
			for(int k = y1; k <= yn; k++){
				grid[k][xn+1] = nx++;
			}
			fix(x1,y1,xn+1,yn);
		} else if(down >= left && down >= right && down >= up){
			for(int k = x1; k <= xn; k++){
				grid[yn+1][k] = nx++;
			}
			fix(x1,y1,xn,yn+1);
		} else if(left >= up && left >= right && left >= down){
			for(int k = y1; k <= yn; k++){
				grid[k][x1-1] = nx++;
			}
			fix(x1-1,y1,xn,yn);
		} else {
			for(int k = x1; k <= xn; k++){
				grid[y1-1][k] = nx++;
			}
			fix(x1,y1-1,xn,yn);
		}
	};
	fix((n+1)/2,(n+1)/2,(n+1)/2,(n+1)/2);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << grid[i][j] << " \n"[j==n]; 
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