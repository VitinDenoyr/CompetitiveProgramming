//https://codeforces.com/problemset/problem/2104/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int a,b,c; cin >> a >> b >> c;
	if(a+b+c >= 3*b && (a+b+c)%3 == 0){
		cout << "YES\n";
	} else {
		cout << "NO\n";
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