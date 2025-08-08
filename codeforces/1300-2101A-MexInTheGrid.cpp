//https://codeforces.com/problemset/problem/2101/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
 
void solve(){
 
	ll n; cin >> n;
	vector<int> dx = {1,0,-1,0}, dy = {0,-1,0,1};
	vector<vector<int>> grid (n+1, vector<int> (n+1, 0));
	ll nx = 0;
	
	function<int(int,int,int,int)> putE = [&](int qt, int dir, int px, int py) -> int {
		for(int i = 1; i <= qt; i++){
			grid[px][py] = nx++;
			if(i == qt){
				if(dir != 3){
					dir++;
				} else {
					px += dx[dir];
					py += dy[dir];
					dir = 0;
					qt += 2;
					break;
				}
			}
			px += dx[dir];
			py += dy[dir];
		}
		if(nx != n*n){
			putE(qt,dir,px,py);
		}
		return 0;
	};
	
	if(n%2){
		grid[(n+1)/2][(n+1)/2] = 0; nx++;
		if(n>1) putE(2,0,(n+1)/2,(n+1)/2 + 1);
	} else {
		putE(1,0,n/2+1,n/2+1);
	}
 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << grid[i][j] << " \n"[j==n];
		}
	}
}
 
int32_t main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
 
	return 0;
}