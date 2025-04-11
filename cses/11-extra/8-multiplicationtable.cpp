#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll n; cin >> n;

	ll l = 1, r = n*n;
	while(l < r){
		ll mid = (l+r)/2;
		ll qt_le = 0, qt_l = 0;
		for(ll i = 1; i <= n; i++){
			qt_le += (min(mid,n*i)/i);
			qt_l += (min(mid-1,n*i)/i);
		}
		if(qt_le <= ((n*n)/2)){
			l = mid+1;
		} else {
			r = mid;
		}
	}
	cout << l << "\n";

	return 0;
}