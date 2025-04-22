//https://codeforces.com/contest/2078/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n,k; cin >> n >> k;
	for(int i = 1; i <= n-2; i++){
		cout << n-((k-1)%2) << " ";
	}
	cout << n << " " << n-1 << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}