//https://codeforces.com/contest/2109/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

ll calc(int a, int b){
	int r = 0;
	while(a > 1){
		a -= a/2;
		r++;
	}
	while(b > 1){
		b -= b/2;
		r++;
	}
	return r;
}

void solve(){

	int n,m,a,b; cin >> n >> m >> a >> b;
	cout << min(min(calc(a,m),calc(n-(a-1),m)),min(calc(n,m-(b-1)),calc(n,b))) + 1 << "\n";

}

int32_t main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}