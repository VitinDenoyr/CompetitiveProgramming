//https://codeforces.com/problemset/problem/2065/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

bool comp(vector<ll>& a, vector<ll>& b){
	return a[0] > b[0];
}

void solve(){

	ll n, m; cin >> n >> m;
	vector<vector<ll>> a (n, vector<ll>(m+1, 0));
	for(ll i = 0; i < n; i++){
		for(ll j = 1; j <= m; j++){
			cin >> a[i][j];
			a[i][0] += a[i][j];
		}
	}
	sort(a.begin(),a.end(),comp);

	ll score = 0;
	for(ll i = 0; i < n; i++){
		for(ll j = 1; j <= m; j++){
			score += a[i][j] * ((ll)n*m - (ll)i*m - (j-1)); 
		}
	}
	cout << score << "\n";
}

int main(){

	ll t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}