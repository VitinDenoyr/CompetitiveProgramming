//https://codeforces.com/problemset/problem/2106/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n,m; cin >> n >> m;
	vector<int> a (n+1, 0), b (m+1, 0);
	vector<int> bestF (m+2, n+1), bestB (m+2, 0);
	bestF[0] = 0; bestB[0] = n+1;
	int bF = 1, bB = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> b[i];
	}
	for(int i = 1; i <= n; i++){
		if(a[i] >= b[bF]){
			bestF[bF] = i;
			bF++;
			if(bF > m) break;
		}
	}
	for(int i = n; i >= 1; i--){
		if(a[i] >= b[m+1-bB]){
			bestB[bB] = i;
			bB++;
			if(bB > m) break;
		}
	}
	int ans = 1000000001;
	for(int i = 0; i < m; i++){
		if(bestF[i] < bestB[m-i-1]){
			ans = min(ans, b[i+1]);
		}
	}
	if(bestF[m] <= n) ans = 0;

	if(ans > 1000000000){
		cout << -1 << "\n";
	} else {
		cout << ans << "\n";
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