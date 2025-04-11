//https://codeforces.com/problemset/problem/2084/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MX = 1000000000000000001ll;

ll mdc(ll a, ll b){
	if(a > b) swap(a,b);
	if(a == 0) return b;
	return mdc(b%a,a);
}

void solve(){

	ll n; cin >> n;
	vector<ll> a (n+1, 0ll);
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());

	if(a[1] == a[2]){
		cout << "YES\n";
		return;
	} else {
		ll acm = 0;
		for(int i = 2; i <= n; i++){
			if(mdc(a[i],a[1]) == a[1]){
				acm = mdc(acm,a[i]);
			}
		}
		if(acm != a[1]){
			cout << "NO\n";
			return;
		} else {
			cout << "YES\n";
			return;
		}
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