//https://codeforces.com/problemset/problem/2114/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int s; cin >> s;
	for(int i = 0; i*i <= s; i++){
		if(i*i == s){
			cout << 0 << " " << i << "\n";
			return;
		}
	}
	cout << -1 << "\n";

}

int32_t main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}