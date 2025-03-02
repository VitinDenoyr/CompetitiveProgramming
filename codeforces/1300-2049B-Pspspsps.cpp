//https://codeforces.com/problemset/problem/2049/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	string s; cin >> s; s = " " + s;
	vector<int> pmin (n+2, 0), pmax (n+2, 0), smin (n+2, 0), smax (n+2, 0);
	int qtp = 0, qts = 0;
	for(int i = 1; i <= n; i++){
		if(i < n && s[i] == 'p') qtp++;
		if(i > 1 && s[i] == 's') qts++;
	}
	if(qtp > 0 && qts > 0){
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}

}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}