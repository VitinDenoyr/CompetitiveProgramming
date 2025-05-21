//https://codeforces.com/gym/105505/problem/K
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

char neg(char c){
	if(c == '1') return '0';
	return '1';
}

void solve(){

	int n; string s;
	cin >> n >> s;
	if(n == 2){
		int dif0 = 0, dif1 = 0;
		string s0 = "", s1 = "";
		for(int i = 0; i < s.length(); i++){
			dif0 += (s[i] == (char)('0'+(i+1)%2));
			s0 += (char)('0'+(i)%2);
			dif1 += (s[i] == (char)('0'+i%2));
			s1 += (char)('0'+(i+1)%2);
		}
		if(dif0 < dif1){
			cout << dif0 << " " << s0 << "\n";
		} else {
			cout << dif1 << " " << s1 << "\n";
		}
	} else {
		vector<pii> v;
		int t0 = 0, sz = 1;
		for(int i = 1; i < s.length(); i++){
			if(s[i] != s[i-1]){
				if(sz >= n){
					v.push_back({t0,sz});
				}
				t0 = i;
				sz = 1;
			} else {
				sz++;
			}
		}
		if(sz >= n){
			v.push_back({t0,sz});
		}
		
		int qt = 0;
		for(pii p : v){
			for(int i = n; i <= p.second; i += n){
				qt++;
				if(p.first + i < s.length() && s[p.first + i - 1] != s[p.first + i]){
					s[p.first + i - 2] = neg(s[p.first + i - 2]);
				} else {
					s[p.first + i - 1] = neg(s[p.first + i - 1]);
				}
			}
		}
		cout << qt << " " << s << "\n";
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	solve();
	return 0;

}