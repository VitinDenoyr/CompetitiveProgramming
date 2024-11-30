//https://codeforces.com/problemset/problem/1985/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define prllvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl
#define MAXN 200005ll

ll n,h;
ll dmg[MAXN], cdwn[MAXN];

ll calc(ll k){
	ll dam = 0;
	for(ll i = 0; i < n; i++){
		dam += dmg[i]*((k-1)/cdwn[i] + 1);
		if(dam >= h) return dam;
	}
	return dam;
}

int main(){

	ll ts; cin >> ts;
	for(ll it = 0; it < ts; it++){
		cin >> h >> n;
		for(ll i = 0; i < n; i++){
			cin >> dmg[i];
		}
		for(ll i = 0; i < n; i++){
			cin >> cdwn[i];
		}
		ll l = 1, r = MAXN*MAXN; 
		while(l < r){
			ll mid = (l+r)/2;
			ll res = calc(mid);
			if(res >= h){
				r = mid;
			} else {
				l = mid+1;
			}
		}
		cout << l << "\n";
	}

	return 0;
}