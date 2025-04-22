//https://codeforces.com/problemset/problem/2093/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	string n; cin >> n;
	vector<int> qt (10, 0);
	for(char c : n){
		qt[c-'0']++;
	}

	int backz = 0;
	for(int i = n.size()-1; i >= 0; i--){
		if(n[i] == '0'){
			backz++;
		} else {
			break;
		}
	}

	int sqt = 0;
	for(int i = 1; i <= 9; i++){
		sqt += qt[i];
	}

	cout << sqt - 1 + (backz) << "\n";

}

int32_t main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}