#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	ll k; cin >> k;

	if(k == 0){
		cout << 1 << "\n";
		cout << "69 69\n";
		return;
	}
	ll acc = 0, pts = 0;
	vector<ll> accs;
	while(acc < k){
		ll l = 0, r = 500;
		while(l < r){
			ll mid = (l+r+1)/2;
			ll res = (mid*(mid-1))/2;
			if(res > (k-acc)){
				r = mid-1;
			} else {
				l = mid;
			}
		}
		acc += (l*(l-1))/2;
		pts += l;
		accs.push_back(l);
	}

	int a = 1, b = 1;
	cout << pts << "\n";
	for(ll x : accs){
		for(ll i = 1; i <= x; i++){
			cout << a << " " << b << "\n";
			b++;
		}
		a++;
	}
}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}