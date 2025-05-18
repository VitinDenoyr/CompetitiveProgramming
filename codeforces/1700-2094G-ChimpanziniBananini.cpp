//https://codeforces.com/problemset/problem/2094/G
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

void solve(){

	int q; cin >> q;
	deque<ll> a; ll back = 1; ll sum = 0, sigma = 0;
	for(ll iq = 1; iq <= q; iq++){
		ll s; cin >> s;
		if(s == 3){
			ll k; cin >> k;
			if(back){
				a.push_back(k);
			} else {
				a.push_front(k);
			}
			sum += k;
			sigma += a.size()*k;
			cout << sigma << "\n";
		} else if(s == 1){
			sigma += sum;
			if(back){
				sigma -= a.back()*a.size();
				a.push_front(a.back());
				a.pop_back();
			} else {
				sigma -= a.front()*a.size();
				a.push_back(a.front());
				a.pop_front();
			}
			cout << sigma << "\n";
		} else {
			back = 1 - back;
			sigma = (a.size()+1)*sum - sigma;
			cout << sigma << "\n";
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