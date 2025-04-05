//https://codeforces.com/contest/2072/problem/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void printe(int m, int k){
	if(m == 1){
		cout << k << " ";
		return;
	}
	int p = 1, e = 0;
	while(p < m){
		p *= 2;
		e++;
	}
	int rem = p - m;
	int streak = (m - (p-m))/2;
	printe(streak,k);
	for(int i = 1; i <= rem; i++){
		cout << 0 << " ";
	}
	printe(streak,k);
}

void solve(){

	int n,k; cin >> n >> k;

	printe(n,k);
	cout << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}