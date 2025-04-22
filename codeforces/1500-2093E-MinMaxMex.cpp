//https://codeforces.com/problemset/problem/2093/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

void solve(){

	ll n,k; cin >> n >> k;
	vector<ll> a (n+1, 0);
	map<ll,ll> qt;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		qt[a[i]]++;
	}

	if(qt[0] < k){
		cout << 0 << "\n";
		return;
	} else {
		ll l = 0, r = (n+k-1)/k;
		while(l < r){
			ll mid = (l+r+1)/2;

			function<bool()> canMake = [&]() -> bool{
				//Verifica se tem como dividir em k partes cada uma com mex >= mid.
				ll j = 1;
				vector<ll> exist (mid*k+9, 0);
				ll dones = 0;
				for(ll x = 1; x <= k; x++){
					ll rem = mid;
					while(j <= n && rem > 0){
						if(a[j] < mid && exist[(x-1)*mid + a[j]] == 0){
							exist[(x-1)*mid + a[j]] = 1;
							rem--;
						}
						j++;
						if(rem == 0){
							dones++;
							break;
						}
					}
					if(j > n) break;
				}

				if(dones == k){
					return true;
				} else {
					return false;
				}
			};

			bool ans = canMake();
			if(ans){
				l = mid;
			} else {
				r = mid-1;
			}
		}
		cout << l << "\n";
	}

}

int32_t main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}