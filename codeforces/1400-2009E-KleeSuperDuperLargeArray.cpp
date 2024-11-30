//https://codeforces.com/problemset/problem/2009/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll

int main(){

	int t; cin >> t;
	while(t--){
		ull n,k; cin >> n >> k;
		ull tot = (n*(n+1))/2 + (k-1)*n; //3 4 5 6 7

		ull l = 1, r = n;
		ull counter = 0;
		while(l < r){
			counter++;
			ull ind = (l+r)/2;
			ull res = (ind*(ind+1))/2 + (k-1)*ind;
			if(res < (tot - res)){
				l = ind;
			} else if(res > (tot - res)){
				r = ind;
			} else {
				l = ind; r = ind; break;
			}
			if(counter >= 40) break;
		}
		if(l == r) {
			ll mval = abs((ll)((l*(l+1))/2 + (k-1)*l) - (ll)(tot - ((l*(l+1))/2 + (k-1)*l)));
			cout << mval << "\n";
		} else {
			ll m = l, mval = abs((ll)((l*(l+1))/2 + (k-1)*l) - (ll)(tot - ((l*(l+1))/2 + (k-1)*l)));
			for(ll it = l; it <= r; it++){
				if(abs((ll)((it*(it+1))/2 + (k-1)*it) - (ll)(tot - ((it*(it+1))/2 + (k-1)*it))) < mval){
					m = it; mval = abs((ll)((it*(it+1))/2 + (k-1)*it) - (ll)(tot - ((it*(it+1))/2 + (k-1)*it)));
				}
			}
			cout << mval << "\n";
		}
	}

	return 0;
}