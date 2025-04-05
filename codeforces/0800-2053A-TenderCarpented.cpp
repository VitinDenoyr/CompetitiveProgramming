//https://codeforces.com/problemset/problem/2053/A
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
		if((a[i] == a[i+1]) || (a[i] < a[i+1] && 2*a[i] > a[i+1]) || (a[i] > a[i+1] && a[i] < 2*a[i+1])){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
	return;
}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}