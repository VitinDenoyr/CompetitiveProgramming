//https://codeforces.com/contest/2102/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	ll n; cin >> n;
	vector<ll> a (n+1, 0), b;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b.push_back(abs(a[i]));
	}
	ll x = abs(a[1]);
	sort(b.begin(),b.end());
	for(int i = 0; i <= (n)/2; i++){
		if(b[i] == x){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";

}

int32_t main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}