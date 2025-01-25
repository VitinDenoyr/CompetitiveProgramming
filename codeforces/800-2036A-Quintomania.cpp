//https://codeforces.com/problemset/problem/2036/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	int n; cin >> n;
	vector<int> nt (n+1, 0);
	int r = 1;
	for(int i = 1; i <= n; i++){
		cin >> nt[i];
		if(i > 1){
			if(abs(nt[i] - nt[i-1]) != 7 && abs(nt[i] - nt[i-1]) != 5){
				r = 0;
			}
		}
	}
	if(r){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main(){

	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}