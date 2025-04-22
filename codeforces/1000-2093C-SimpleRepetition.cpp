//https://codeforces.com/problemset/problem/2093/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

void solve(){

	ll n,k;
	cin >> n >> k;
	if((k > 1 && n != 1) || (k == 1 && n == 1)){
		cout << "NO\n";
		return;
	} else {
		if(k == 1){
			for(ll i = 2; i*i <= n; i++){
				if(n%i == 0){
					cout << "NO\n";
					return;
				}
			}
			cout << "YES\n";
			return;
		} else if(n == 1){ //1 11 111
			ll xx = 1;
			for(int i = 1; i <= k-1; i++){
				xx = 10*xx + 1;
			}

			for(ll i = 2; i*i <= xx; i++){
				if(xx%i == 0){
					cout << "NO\n";
					return;
				}
			}
			cout << "YES\n";
			return;
		}
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}