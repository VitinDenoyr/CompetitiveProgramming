//https://codeforces.com/problemset/problem/2060/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){

	int a[6];
	cin >> a[1] >> a[2] >> a[4] >> a[5];

	int p1 = a[1] + a[2];
	int p2 = a[4] - a[2];
	int p3 = a[5] - a[4];

	map<int,int> qt;
	int resp = 0;
	qt[p1]++; resp = max(qt[p1],resp);
	qt[p2]++; resp = max(qt[p2],resp);
	qt[p3]++; resp = max(qt[p3],resp);
	cout << resp << "\n";
}

int main(){

	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}