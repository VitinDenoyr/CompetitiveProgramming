//https://codeforces.com/contest/2136/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int a,b,c,d; cin >> a >> b >> c >> d;
	c -= a; d -= b;
	if(a > 2*b+2 || b > 2*a+2 || c > 2*d+2 || d > 2*c+2){
		cout << "NO\n";
	} else {
		cout << "YES\n";
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