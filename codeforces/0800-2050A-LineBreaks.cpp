//https://codeforces.com/problemset/problem/2050/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n,m,r=0; cin >> n >> m;
	for(int i = 1; i <= n; i++){
		string s = "x"; cin >> s;
		if(m >= s.length()){
			m -= s.length();
			r++;
		} else {
			m = 0;
		}
	}
	cout << r << "\n";

}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}