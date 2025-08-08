//https://codeforces.com/problemset/problem/474/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const ll mod = 1000000007ll;

int k;
vector<ll> dp (101000, 0), su (101000, 0);

void solve(){

	int a,b; cin >> a >> b;
	cout << ((su[b] - su[a-1])%mod + mod)%mod << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t >> k;

	dp[0] = 1;
	for(int i = 1; i <= 100000; i++){
		dp[i] = dp[i-1];
		if(i >= k) dp[i] = (dp[i] + dp[i-k])%mod;
	}
	su[0] = 0;
	for(int i = 1; i <= 100000; i++){
		su[i] = (su[i-1] + dp[i])%mod;
	}

	while (t--){
		solve();
	}
	return 0;

}