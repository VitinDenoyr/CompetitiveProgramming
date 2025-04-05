//https://codeforces.com/contest/2085/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
 
void solve(){
 
	ll x, y; cin >> x >> y;
	if(x == y){
		cout << -1 << "\n";
		return;
	}
	ll k = 0;
	for(ll b = 0; b <= 30; b++){
		//cout << b << "\n";
		if(((x & (1<<b)) != 0) && ((y & (1<<b)) != 0)){
			//cout << "equal\n";
			ll dx = (1<<b) - (x & ((1<<b) - 1));
			ll dy = (1<<b) - (y & ((1<<b) - 1));
			k += min(dx,dy);
			x += min(dx,dy);
			y += min(dx,dy);
		}
	}
	cout << k << "\n";
 
}
 
int main(){
 
	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll t; cin >> t;
	while(t--){
		solve();
	}
 
	return 0;
}