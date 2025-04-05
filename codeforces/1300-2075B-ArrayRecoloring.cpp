//https://codeforces.com/problemset/problem/2075/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n,k; cin >> n >> k;
	vector<ll> a (n+1, 0);
	vector<pii> b;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b.push_back({a[i],i});
	}

	sort(b.begin(),b.end());
	ll s = 0;
	for(int i = 0; i <= k; i++){
		s += b[n-i-1].first;
	}

	if(k == 1){
		s = 0;
		for(int i = 2; i < n; i++){
			s = max(s, a[i] + max(a[1],a[n]));
		}
		s = max(s, a[1]+a[n]);
	}
	cout << s << "\n";
	
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}