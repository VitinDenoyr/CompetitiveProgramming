//https://codeforces.com/contest/2111/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n,m; cin >> n >> m;
	vector<int> w (m+1, 0), l (m+1, 0), h (m+1, 0);
	vector<ll> fib (n+1, 0);
	fib[1] = 1; fib[2] = 2; fib[0] = 0;
	for(int i = 3; i <= n; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}	

	string s = "";
	for(int i = 1; i <= m; i++){
		cin >> w[i] >> l[i] >> h[i];
		ll x1 = fib[n], x2 = fib[n], x3 = fib[n]+fib[n-1];
		if(w[i] >= x1 && l[i] >= x2 && h[i] >= x3){
			s += "1";
			continue;
		} else if(w[i] >= x1 && l[i] >= x3 && h[i] >= x2){
			s += "1";
			continue;
		} else if(w[i] >= x3 && l[i] >= x2 && h[i] >= x1){
			s += "1";
			continue;
		} else {
			s += "0";
			continue;
		}
	}
	cout << s << "\n";


}

int32_t main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}