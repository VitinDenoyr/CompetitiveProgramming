//https://codeforces.com/contest/2069/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<int> a (n+1, 0), b (n+1, 0);
	for(int i = 2; i <= n-1; i++){
		cin >> b[i];
	}

	bool vl = true;
	for(int i = 3; i <= n-2; i++){
		if(b[i] == 0 && b[i+1] == 1 && b[i-1] == 1){
			vl = false;
		}
	}
	if(vl){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}