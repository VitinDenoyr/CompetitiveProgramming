//https://codeforces.com/problemset/problem/2093/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	ll n; cin >> n;
	if(n%2 == 1){
		cout << "YES\n";
	} else {
		cout << "NO\n";
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