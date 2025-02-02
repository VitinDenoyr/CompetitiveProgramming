//https://codeforces.com/problemset/problem/2062/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){

	string s; cin >> s;
	int qt = 0;
	for(char c : s){
		if(c == '1') qt++;
	}
	cout << qt << "\n";

}

int main(){

	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}