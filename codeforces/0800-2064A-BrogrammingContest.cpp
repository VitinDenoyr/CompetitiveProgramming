//https://codeforces.com/problemset/problem/2064/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	string s; int n; cin >> n >> s; s = "0" + s;
	int qt = 0;
	for(int i = 1; i <= n; i++){
		if(s[i-1] == '0' && s[i] == '1') qt++;
	}
	cout << 2*qt - (s[n] == '1') << "\n";

}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}