//https://codeforces.com/problemset/problem/2048/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << (n%33 == 0 ? "YES" : "NO") << "\n";
	}

	return 0;
}