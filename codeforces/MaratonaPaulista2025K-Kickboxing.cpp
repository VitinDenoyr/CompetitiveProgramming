//https://codeforces.com/gym/105904/problem/K
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const ll mod = 998244353;

void solve(){

	ll n,k; cin >> n >> k;

	vector<vector<ll>> dp (n+1, vector<ll>(n+1,0));
	for(int i = 1; i <= n; i++){
		dp[0][i] = 1;
	}

	for(int i = 1; i <= n; i++){
		ll acc = 0;
		for(int j = 1; j <= n; j++){
			if(i-j >= 0 && j != k) acc = (acc + dp[i-j][j])%mod;
			dp[i][j] = acc;
		}
	}

	cout << dp[n][n] << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	solve();
	return 0;

}