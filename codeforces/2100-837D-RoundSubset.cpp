//https://codeforces.com/problemset/problem/837/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const ll MAXN = 201;

void solve(){

	ll n,k; cin >> n >> k;
	vector<ll> q2 (n+1, 0), q5 (n+1, 0), a (n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		while(a[i]%2 == 0){
			a[i]/=2;
			q2[i]++;
		}
		while(a[i]%5 == 0){
			a[i]/=5;
			q5[i]++;
		}
	}

	vector<vector<vector<ll>>> dp (2, vector<vector<ll>> (n+1, vector<ll> (27*n + 1, -1000000000ll)));
	dp[0][0][0] = 0; ll mxf = 0, resp = 0;
	for(ll i = 1; i <= n; i++){ //considerarei a[i]
		for(int j = 0; j <= min(k,i-1); j++){ //tendo j escolhidos
			for(int f = 0; f <= mxf; f++){
				if(j < k){
					dp[i%2][j+1][f+q5[i]] = max(dp[i%2][j+1][f+q5[i]],dp[(i-1)%2][j][f] + q2[i]);
					resp = max(resp, min(f+q5[i],dp[(i-1)%2][j][f]+q2[i]));
				}
				dp[i%2][j][f] = max(dp[(i-1)%2][j][f],dp[i%2][j][f]);
			}
		}
		mxf += q5[i];
	}

	cout << resp << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t = 1;
	while (t--){
		solve();
	}
	return 0;

}