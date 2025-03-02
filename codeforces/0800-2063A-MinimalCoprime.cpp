//https://codeforces.com/problemset/problem/2063/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int l,r; cin >> l >> r;
	if(l+r != 2){
		cout << (r - l) << "\n";
	} else {
		cout << 1 << "\n";
	}
}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}