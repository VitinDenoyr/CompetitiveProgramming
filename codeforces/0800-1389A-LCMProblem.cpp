//https://codeforces.com/problemset/problem/1389/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int l,r; cin >> l >> r;
	if(r < 2*l){
		cout << -1 << " " << -1 << "\n";
	} else {
		cout << l << " " << 2*l << "\n";
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}