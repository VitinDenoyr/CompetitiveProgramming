//https://codeforces.com/problemset/problem/2082/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	ll x,x0,n,m; cin >> x >> n >> m;
	x0 = x;

	m = min(m,30ll); n = min(n,30ll);
	for(int i=1; i<=n; i++) x /= 2;
	for(int i=1; i<=m; i++) x = (x+1)/2;
	for(int i=1; i<=m; i++) x0 = (x0+1)/2;
	for(int i=1; i<=n; i++) x0 /= 2;
	cout << x0 << " " << x << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}