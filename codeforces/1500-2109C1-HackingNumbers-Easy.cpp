//https://codeforces.com/contest/2109/problem/C1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll d18 = 1000000000000000000ll;

void solve(){

	ll n,ans; cin >> n;
	ll x = 1234;
	cout << "digit" << endl;
	cin >> ans;
 
	cout << "digit" << endl;
	cin >> ans;
 
	ll l = 1, r = 16;
	ll back = 0;
	while(l < r){
		ll mid = (l+r+1)/2;
		cout << "add " << (back + d18 - mid + 1ll) << endl;
		cin >> ans;
		
		if(ans == 1){
			r = mid-1;
			back -= (back + d18 - mid + 1ll);
		} else {
			l = mid;
		}
	}
	cout << "add " << (n - l + back) << endl;
	cin >> ans;
	cout << "!" << endl;
	cin >> ans;

}

int main(){

	ll t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}