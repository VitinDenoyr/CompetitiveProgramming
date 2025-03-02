//https://codeforces.com/problemset/problem/2065/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	string s; cin >> s;
	for(int i = 0; i < s.size()-1; i++){
		if(s[i] == s[i+1]){
			cout << 1 << "\n";
			return;
		}
	}
	cout << s.size() << "\n";

}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}