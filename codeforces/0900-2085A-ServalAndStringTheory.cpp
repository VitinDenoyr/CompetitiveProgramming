//https://codeforces.com/contest/2085/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
 
void solve(){
 
	int n, k; cin >> n >> k;
	string s; cin >> s;
	map<char,int> qt;
	for(char c : s) qt[c]++;
	for(int i = 0; i < (n/2); i++){
		if((s[i]-'a') < (s[n-i-1]-'a')){
			cout << "YES\n";
			return;
		} else if((s[i]-'a') > (s[n-i-1]-'a')){
			if(k == 0){
				cout << "NO\n";
				return;
			} else {
				cout << "YES\n";
				return;
			}
		}
	}
	if(k == 0 || qt[s[0]] == s.size()){
		cout << "NO\n";
	} else {
		cout << "YES\n";
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