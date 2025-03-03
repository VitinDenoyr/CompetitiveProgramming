//https://codeforces.com/problemset/problem/2065/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n,m,k; cin >> n >> m >> k;
	if(abs(n-m) > k || max(n,m) < k){
		cout << "-1\n";
	} else if(n >= m){
		int q0 = k, q1 = 0;
		for(int i = 1; i <= k; i++){
			cout << "0";
		}
		while(q0 < n && q1 < m){
			cout << "10";
			q0++; q1++;
		}
		while(q1 < m){
			cout << "1";
			q1++;
		}
		cout << "\n";
	} else {
		int q0 = 0, q1 = k;
		for(int i = 1; i <= k; i++){
			cout << "1";
		}
		while(q0 < n && q1 < m){
			cout << "01";
			q0++; q1++;
		}
		while(q0 < n){
			cout << "0";
			q0++;
		}
		cout << "\n";
	}
}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}