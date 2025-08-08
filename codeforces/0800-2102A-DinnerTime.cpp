//https://codeforces.com/contest/2102/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	ll n,m,p,q; cin >> n >> m >> p >> q;
	if(n%p == 0 && m != q*(n/p)){
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}

}

int32_t main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}