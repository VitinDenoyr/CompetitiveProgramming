//https://codeforces.com/contest/2107/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int mdc(int a, int b){
	if(a == 0) return b;
	return mdc(b%a,a);
}

void solve(){

	int n; cin >> n;
	vector<int> a (n+1, 0);
	int mx = 0, alleq = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mx = max(mx,a[i]);
		if(i > 1 && a[i] != a[i-1]){
			alleq = 0;
		}
	}

	if(alleq){
		cout << "No\n";
	} else {
		cout << "Yes\n";
		for(int i = 1; i <= n; i++){
			if(a[i] == mx){
				cout << 1 << " \n"[i==n];
			} else {
				cout << 2 << " \n"[i==n];
			}
		}
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