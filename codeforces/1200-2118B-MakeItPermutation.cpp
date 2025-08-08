//https://codeforces.com/problemset/problem/2118/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	if(n%2 == 0){
		cout << 2*n-1 << "\n";
		for(int i = 1; i <= n/2; i++){
			cout << i << " " << 1 << " " << 2*i << "\n";
			if(i<(n/2)) cout << i << " " << 2*i+1 << " " << n << "\n";
		}
		for(int i = 1; i <= n/2; i++){
			cout << i+(n/2) << " " << 1 << " " << 2*i-1 << "\n";
			cout << i+(n/2) << " " << 2*i << " " << n << "\n";
		}
	} else {
		cout << 2*n-1 << "\n";
		for(int i = 1; i <= n/2; i++){
			cout << i << " " << 1 << " " << 2*i << "\n";
			cout << i << " " << 2*i+1 << " " << n << "\n";
		}
		for(int i = 1; i <= (n+1)/2; i++){
			cout << i+(n/2) << " " << 1 << " " << 2*i-1 << "\n";
			if(i<((n+1)/2)) cout << i+(n/2) << " " << 2*i << " " << n << "\n";
		}
	}
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}