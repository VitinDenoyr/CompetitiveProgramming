#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

struct Fenwick {
	ll len; vector<ll> v;
	Fenwick(ll _n){
		len = _n;
		v = vector<ll> (_n + 1, 0);
	}
	void update(ll pos){ //+1 cara <= k com valor pos
		while(pos <= len){
			v[pos]++;
			pos += (pos&(-pos));
		}
	}
	ll query(ll pos){ //qnts caras <= k de 1 até pos
		ll resp = 0;
		while(pos > 0){
			resp += v[pos];
			pos -= (pos&(-pos));
		}
		return resp;
	}
};

void solve(){

	ll n,k; cin >> n >> k;
	vector<ll> a (n+1 , 0), b (n+1, 0);
	map<ll,ll> compr, rev;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		b.push_back(a[i]);
	}

	Fenwick ftree (n+1);
	for(ll i = 1; i <= n; i++){
		if(a[i] <= k){
			ftree.update(i);
		}
	}

	ll rightest = 0;
	for(ll i = n; i >= 1; i--){
		ll rs = ftree.query(n) - ftree.query(i-1);
		if(rs >= (n-i+2)/2){
			rightest = i;
			break;
		}
	}

	ll cd = -1000000001;
	ll ca = 1000000001;
	ll exist = 0;
	for(ll i = 1; i <= n; i++){
		//cout << i << ":\n";
		ll rs = ftree.query(i);
		//cout << rs << " " << ca << "\n";
		if(rs >= (i+1)/2){
			if((rs) - (i - rs) >= ca){
				cout << "YES\n";
				return;
			}
			ca = min(ca, rs - (i - rs));
			if(rightest > i+1){
				cout << "YES\n";
				return;
			}
		}

		ll cpreciso = (i - rs) - (rs);
		if(cd >= cpreciso && i < n){
			if(ftree.query(n) - ftree.query(i) >= (n-i+1)/2){
				cout << "YES\n";
				return;
			}
		}

		if(rs <= i/2){
			cd = max(cd, (i - rs) - rs);
		}
	}
	cout << "NO\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}