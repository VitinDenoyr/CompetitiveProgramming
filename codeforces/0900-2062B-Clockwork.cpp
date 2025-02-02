//https://codeforces.com/problemset/problem/2062/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){

	int n; cin >> n;
	vector<int> a (n+1, 0);
	bool can = true;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] <= max(2*(n-i),2*(i-1))) can = false;
	}
	if(can){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main(){

	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}