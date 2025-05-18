//https://codeforces.com/problemset/problem/2092/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

void solve(){

	ll n; cin >> n;
	vector<ll> a (n+1, 0);
	vector<ll> qt (2, 0);
	ll mx = 0, sum = 0;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		qt[a[i]%2]++;
		sum += a[i];
		mx = max(a[i],mx);
	}

	if(n == 1){
		cout << a[1] << "\n";
		return;
	}

	if(qt[0] == n || qt[1] == n){
		cout << mx << "\n";
	} else {
		cout << sum - qt[1] + 1 << "\n";
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}