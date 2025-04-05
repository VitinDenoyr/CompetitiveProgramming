//https://codeforces.com/problemset/problem/2065/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	string s; cin >> s;
	s[s.size()-2] = 'i';
	cout << s.substr(0,s.size()-1) << "\n";

}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}