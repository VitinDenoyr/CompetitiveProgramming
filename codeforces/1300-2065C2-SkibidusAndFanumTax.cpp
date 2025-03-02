//https://codeforces.com/problemset/problem/2065/C2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

void solve(){

	ll n,m; cin >> n >> m;
	vector<ll> a(n+1, 0), b(m, 0), c(n+1, 0);
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(ll i = 0; i < m; i++){
		cin >> b[i];
	}

	sort(b.begin(),b.end());
	c[1] = min(a[1],b[0]-a[1]);
	bool failed = false;

	for(ll i = 2; i <= n; i++){
		ll l = 0, r = m-1;
		while(l < r){
			ll mid = (l+r)/2;
			if(b[mid]-a[i] >= c[i-1]){
				r = mid;	
			} else {
				l = mid+1;
			}
		}
		if(b[l]-a[i] < c[i-1]){
			c[i] = a[i];
		} else if(a[i] < c[i-1]){
			c[i] = b[l]-a[i];
		} else {
			c[i] = min(a[i],b[l]-a[i]);
		}
		if(c[i] < c[i-1]) failed = true;
	}

	if(failed){
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}

}

int main(){

	ll t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}