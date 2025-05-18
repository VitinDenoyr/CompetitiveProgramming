//https://codeforces.com/problemset/problem/1611/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

void solve(){

	ll n,s; cin >> n >> s;
	vector<ll> a (n+2, 0);
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	a[n+1] = -100000000000000000ll;
	ll lc = 0, rc = 0;
	ll l = 1, r = 1, v = 0;
	while(true){
		if(v - a[r] <= s){
			v -= a[r]; r++;
			continue;
		} else {
			if(r-l > rc-lc){
				lc = l;
				rc = r;
			}
			if(r >= n+1) break;
			v += a[l];
			l++;
			if(r < l){
				r = l;
				v -= a[l-1];
			}
		}
	}
	if(rc > lc){
		cout << lc << " " << rc-1 << "\n";
	} else {
		cout << -1 << "\n";
	}
}

int main(){

	ll t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}