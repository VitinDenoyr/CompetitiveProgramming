//https://codeforces.com/contest/2136/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

vector<queue<int>> v (200002, queue<int>());

void solve(){

	int n; cin >> n;
	vector<int> a (n+1, 0), dp (n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		while(!v[a[i]].empty()) v[a[i]].pop();
	}

	int lns = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 1){
			dp[i] = dp[i-1]+1;
		} else if(v[a[i]].size() == a[i]-1){
			dp[i] = max(dp[i-1],dp[v[a[i]].front()-1]+a[i]);
			v[a[i]].push(i);
			v[a[i]].pop();
		} else {
			dp[i] = dp[i-1];
			v[a[i]].push(i);
		}
	}

	cout << dp[n] << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}