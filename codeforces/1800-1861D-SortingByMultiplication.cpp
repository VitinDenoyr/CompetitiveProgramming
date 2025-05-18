//https://codeforces.com/problemset/problem/1861/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<int> a (n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	vector<int> ge (n+2, 0), le (n+1, 0); 
	for(int i = 2; i <= n; i++){
		ge[i] = ge[i-1];
		if(a[i] <= a[i-1]) ge[i]++;
		le[i] = le[i-1];
		if(a[i] >= a[i-1]) le[i]++;
	}
	ge[n+1] = ge[n];

	int resp = ge[n];
	for(int i = 1; i <= n; i++){
		resp = min(resp, le[i] + (ge[n] - ge[i+1]) + 1);
	}
	cout << resp << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}