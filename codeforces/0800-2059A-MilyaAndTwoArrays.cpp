//https://codeforces.com/problemset/problem/2059/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<int> a (n+1, 0), b (n+1, 0);
	map<int,int> qta, qtb;
	int qa = 0, qb = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		qta[a[i]]++;
		if(qta[a[i]] == 1) qa++;
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
		qtb[b[i]]++;
		if(qtb[b[i]] == 1) qb++;
	}
	if(qa >= 3 || qb >= 3 || (qa >= 2 && qb >= 2)){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}