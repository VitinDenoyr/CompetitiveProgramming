//https://codeforces.com/problemset/problem/2114/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<int> a (n+1, 0);
	int last = -2, qta = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] - last > 1){
			qta++;
			last = a[i];
		}
	}
	cout << qta << "\n";

}

int32_t main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}