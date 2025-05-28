//https://codeforces.com/problemset/problem/2114/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
 
void solve(){
 
	int n,k; cin >> n >> k;
	vector<int> qt (2, 0);
	string s; cin >> s;
	for(char c: s){
		qt[c-'0']++;
	}
 
	int rem = abs(qt[0] - qt[1])/2;
	if(k >= rem && (k != n/2 || qt[0]%2 == 0) && (k-rem)%2 == 0){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
 
}
 
int32_t main(){
 
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}
 
	return 0;
}