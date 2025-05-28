//https://codeforces.com/problemset/problem/1475/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	ll n; cin >> n;
	int k = 1;
	while((1ll<<k) <= n){
		if((1ll<<k) == n){
			cout << "NO\n";
			return;
		} else {
			k++;
		}
	}
	cout << "YES\n";
	return;

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}