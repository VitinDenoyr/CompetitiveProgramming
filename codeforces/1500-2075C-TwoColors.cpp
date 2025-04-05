//https://codeforces.com/problemset/problem/2075/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

struct Bitree {
	ll len; vector<ll> v;
	Bitree(ll _n){
		len = _n; v = vector<ll> (_n+1, 0);
	}
	ll query(ll u){
		ll resp = 0;
		while(u > 0){
			resp += v[u];
			u -= (u&(-u));
		}
		return resp;
	}
	void update(ll pos){
		while(pos <= len){
			v[pos]++;
			pos += (pos&(-pos));
		}
	}
};

void solve(){

	ll n,m; cin >> n >> m;
	vector<ll> p (m+1, 0);
	Bitree b (n);
	for(ll i = 1; i <= m; i++){
		cin >> p[i];
		b.update(p[i]);
	}

	ll r = 0;
	for(ll i = 1; i < n; i++){
		ll x1 = m - b.query(i-1);
		ll xn = m - b.query(n-i-1);
		r += (x1*xn - min(x1,xn));
	}
	cout << r << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}