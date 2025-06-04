//https://codeforces.com/contest/2111/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int x; cin >> x;
	int k = 0, r = 0;
	while(k < x){
		k = (2*k + 1);
		if(k > x){
			k = x;
		}
		r++;
	}
	cout << 2*r + 1 << "\n";

}

int32_t main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}