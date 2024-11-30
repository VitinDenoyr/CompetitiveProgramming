//https://codeforces.com/problemset/problem/1999/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define printvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl

int main(){

	int t; cin >> t;
	for(int it = 0; it < t; it++){
		string s,r,res; int ind = 0;
		cin >> s >> r;
		for(int i = 0; i < s.size(); i++){
			if(ind < r.size() && (s[i] == r[ind] || s[i] == '?')){
				res += r[ind++]; 
			} else {
				if(s[i] == '?'){
					res += 'a';
				} else {
					res += s[i];
				}
			}
		}
		if(ind == r.size()){
			cout << "YES\n";
			cout << res << "\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}