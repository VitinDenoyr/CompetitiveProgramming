//https://codeforces.com/contest/2109/problem/A
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

	for(int i = 1; i < n; i++){
		if(a[i] == 0 && a[i+1] == 0){
			cout << "YES\n";
			return;
		}
	}

	int qt0 = 0;
	for(int i = 1; i <= n; i++){
		qt0 += (a[i] == 0);
	}
	if(qt0 == 0){
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
	return;

}

int32_t main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}