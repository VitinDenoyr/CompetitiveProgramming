//https://codeforces.com/problemset/problem/2093/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

ll whichTable(ll l, ll r, ll u, ll d, ll nx, ll x, ll y){
	//cout << nx << "!\n";
	if(l == r) return nx;
	ll qtEach = ((r-l+1ll)/2ll)*((d-u+1ll)/2ll);
	//cout << "each " << qtEach << "\n";
	if(x <= (l+r-1)/2 && y <= (u+d-1)/2){
		//cout << "first\n";
		return whichTable(l,(l+r-1)/2,u,(u+d-1)/2,nx,x,y);
	} else if(x > (l+r-1)/2 && y > (u+d-1)/2){
		//cout << "sec\n";
		return whichTable((l+r-1)/2 + 1,r,(u+d-1)/2 + 1,d,nx + qtEach,x,y);
	} else if(x <= (l+r-1)/2 && y > (u+d-1)/2){
		//cout << "thir\n";
		return whichTable(l,(l+r-1)/2,(u+d-1)/2 + 1,d,nx + qtEach*2ll,x,y);
	} else {
		//cout << "four\n";
		return whichTable((l+r-1)/2 + 1,r,u,(u+d-1)/2,nx + qtEach*3ll,x,y);
	}
}

pii whichVal(ll l, ll r, ll u, ll d, ll nx, ll k){
	if(l == r) return {l,u};
	ll qtEach = ((r-l+1ll)/2ll)*((d-u+1ll)/2ll);
	if((ll)(nx + qtEach*1ll) > k){
		return whichVal(l,(l+r-1)/2,u,(u+d-1)/2,nx,k);
	} else if((ll)(nx + qtEach*2ll) > k){
		return whichVal((l+r-1)/2 + 1,r,(u+d-1)/2 + 1,d,nx + qtEach,k);
	} else if((ll)(nx + qtEach*3ll) > k){
		return whichVal(l,(l+r-1)/2,(u+d-1)/2 + 1,d,nx + qtEach*2ll,k);
	} else {
		return whichVal((l+r-1)/2 + 1,r,u,(u+d-1)/2,nx + qtEach*3ll,k);
	}
}

void solve(){

	ll n,q; cin >> n >> q;
	
	for(ll i = 1; i <= q; i++){
		string s1; cin >> s1;
		if(s1 == "->"){
			ll x,y; cin >> x >> y;
			ll l = 1, r = (1ll<<n);
			ll u = 1, d = (1ll<<n);
			ll resp = whichTable(l,r,u,d,1,y,x);
			cout << resp << "\n";			

		} else {
			ll x; cin >> x;
			ll l = 1, r = (1ll<<n);
			ll u = 1, d = (1ll<<n);
			pii resp = whichVal(l,r,u,d,1,x);
			cout << resp.second << " " << resp.first << "\n";
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