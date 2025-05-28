//https://codeforces.com/problemset/problem/2106/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

void solve(){

	ll n,k; cin >> n >> k;
	vector<ll> a (n+1, 0), b (n+1, 0);
	ll mxa = 0, mna = k;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		mxa = max(mxa, a[i]);
		mna = min(mna, a[i]);
	}
	ll mx = -1;
	for(ll i = 1; i <= n; i++){
		cin >> b[i];
		if(b[i] != -1){
			mx = max(a[i]+b[i],mx);
		}
	}
	ll resp = 1;
	if(mx == -1){
		resp = max((k+mna+1) - (mxa), 0ll);
	} else {
		for(ll i = 1; i <= n; i++){
			if(b[i] != -1 && a[i] + b[i] != mx){
				resp = 0;
				break;
			}
			if(b[i] == -1 && ((mx - a[i]) < 0 || (mx - a[i]) > k)){
				resp = 0;
				break;
			}
		}
	}
	cout << resp << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}