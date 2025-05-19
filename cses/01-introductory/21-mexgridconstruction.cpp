#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;

	vector<vector<int>> grid (n+1, vector<int>(n+1, 0));
	vector<vector<int>> visL (n+1, vector<int>(2*n+1, 0));
	vector<vector<int>> visC (n+1, vector<int>(2*n+1, 0));
	for(int d = 1; d <= 2*n-1; d++){
		for(int l = 1; l <= n; l++){
			int c = d + 1 - l;
			if(c < 1) break;
			if(c > n) continue;
			
			int k = 0;
			while(visL[l][k] || visC[c][k]) k++;
			grid[l][c] = k;

			visL[l][grid[l][c]] = 1;
			visC[c][grid[l][c]] = 1;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << grid[i][j] << " \n"[j==n];
		}
	}

	return 0;

}