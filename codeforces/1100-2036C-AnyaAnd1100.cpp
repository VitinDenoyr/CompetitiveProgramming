//https://codeforces.com/problemset/problem/2036/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	string s; cin >> s;
	s = ' ' + s;
	int n, q; cin >> q; n = s.length();
	vector<int> has (n+1, 0); int qt = 0;

	for(int i = 1; i <= n-3; i++){
		if(s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0'){
			has[i] = 1; qt++;
		}
	}

	for(int ii = 1; ii <= q; ii++){
		int u,v; cin >> u >> v;
		if(s[u] == ('0'+v)){
			cout << (qt > 0 ? "YES\n" : "NO\n");
		} else {
			for(int i = max(u-3,1); i <= min(u,n-3); i++){
				if(s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0'){
					has[i] = 0; qt--;
				}
			}
			s[u] = ('0'+v);
			for(int i = max(u-3,1); i <= min(u,n-3); i++){
				if(s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0'){
					has[i] = 1; qt++;
				}
			}
			cout << (qt > 0 ? "YES\n" : "NO\n");
		}
	}
}

int main(){

	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}