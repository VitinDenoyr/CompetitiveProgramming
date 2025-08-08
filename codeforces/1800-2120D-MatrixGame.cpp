#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const ll mod = 1000000007ll;

void solve(){

	ll a,b,k; cin >> a >> b >> k;
	ll n = ((a-1)*(k) + 1)%mod;

	function<ll(ll,ll)> fexpo = [&](ll x, ll y) -> ll {
		ll res = 1;
		while(y > 0){
			if(y%2 == 0){
				x = (x*x)%mod;
				y /= 2;
			} else {
				res = (res * x)%mod;
				y--;
			}
		}
		return res;
	};

	ll m = 1;
	for(ll ai = 0; ai < a; ai++){
		m = (m * ((k*(a-1)+1-ai+mod)%mod))%mod;
		m = (m * fexpo((ai+1),mod-2))%mod;
	}
	m = (((m*k)%mod * (b-1) + mod)%mod + 1)%mod;
	cout << n << " " << m << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}
