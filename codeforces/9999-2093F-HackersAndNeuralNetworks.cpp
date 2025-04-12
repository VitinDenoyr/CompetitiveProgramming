//https://codeforces.com/problemset/problem/2093/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

void solve(){

	ll n,m; cin >> n >> m;
	vector<string> a (n+1, "");
	vector<vector<string>> b (m+1, vector<string> (n+1, ""));
	vector<ll> corr (m+1, 0);
	map<ll,ll> exist;

	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		exist[i] = 0;
	}
	ll maxCorr = 0;

	for(ll i = 1; i <= m; i++){
		for(ll j = 1; j <= n; j++){
			cin >> b[i][j];
			if(a[j] == b[i][j]){
				corr[i]++;
				exist[j] = i;
			}
		}
		if(corr[i] > corr[maxCorr]) maxCorr = i;
	}

	ll qtOp = n;
	for(ll i = 1; i <= n; i++){
		if(b[maxCorr][i] != a[i]){
			if(exist[i] == 0){
				cout << -1 << "\n";
				return;
			}
			qtOp += 2;
		}
	}

	cout << qtOp << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}