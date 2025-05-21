//https://codeforces.com/gym/105505/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	string s; cin >> s;
	map<int,int> mp;
	for(char c : s){
		mp[c-'a']++;
	}

	int r = 0;
	for(auto x : mp){
		r++;
	}
	cout << s.length() - r << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t = 1;
	while (t--){
		solve();
	}
	return 0;

}