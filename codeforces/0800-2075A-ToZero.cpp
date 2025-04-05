//https://codeforces.com/contest/2075/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n,k; cin >> n >> k;
	ll op = 0;
	if(n%2 == 1){
		op++;
		if(k%2 == 1){
			n -= k;
		} else {
			n -= k-1;
		}
	}
	if(k%2 == 1) k--;
	op += ((n+k-1)/k);
	cout << op << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}