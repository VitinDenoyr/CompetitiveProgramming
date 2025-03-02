//https://codeforces.com/problemset/problem/2056/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n,m; cin >> n >> m;
	ll peri = 4*m;
	vector<int> x (n+1, 0), y (n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
	}

	for(int i = 2; i <= n; i++){
		peri += 2*x[i] + 2*y[i];
	}

	cout << peri << "\n";
}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}