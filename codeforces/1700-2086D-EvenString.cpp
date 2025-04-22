//https://codeforces.com/problemset/problem/2086/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const ll mod = 998244353;

ll fac[500002] = {1};

ll fexpo(ll a, ll b){
	ll r = 1;
	while(b > 0){
		if(b%2){
			r = (r * a)%mod;
			b--;
		} else {
			a = (a*a)%mod;
			b /= 2;
		}
	}
	return r;
}

void solve(){

	vector<int> qt (26, 0);
	int sum = 0;
	for(int i = 0; i < 26; i++){
		cin >> qt[i];
		sum += qt[i];
	}
	
	vector<int> dp (sum+1, 0);
	dp[0] = 1; sum = 0;
 	for(int i = 0; i < 26; i++){
		if(qt[i] == 0) continue;
		sum += qt[i];
		for(int s = sum; s >= qt[i]; s--){
			dp[s] += dp[s-qt[i]];
		}
	}

	ll tot = ((fac[sum/2] * fac[sum - sum/2])%mod * dp[sum/2])%mod;
	for(int i = 0; i < 26; i++){
		if(qt[i] == 0) continue;
		tot = (tot * fexpo(fac[qt[i]],mod-2))%mod;
	}

	cout << tot << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	for(int i = 1; i <= 500000; i++){
		fac[i] = (fac[i-1] * i)%mod;
	}

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}