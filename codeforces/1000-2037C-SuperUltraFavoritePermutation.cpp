//https://codeforces.com/contest/2037/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	int n; cin >> n; // i i i i i i i p p p p p p p p p p p p
	if (n < 5){
		cout << "-1\n";
	} else {
		for(int i = 1; i <= n; i += 2){
			if(i == 5) continue;
			cout << i << " ";
		}
		cout << 5 << " " << 4 << " ";
		for(int i = 2; i <= n; i += 2){
			if(i == 4) continue;
			cout << i << (" \n")[(i+2) > n];
		}
	}
}

int main(){

	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}