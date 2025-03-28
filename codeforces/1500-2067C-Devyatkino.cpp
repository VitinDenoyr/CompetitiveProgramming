//https://codeforces.com/problemset/problem/2067/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int dist(char c){
	int r = (c-'0')-7;
	if(r < 0) r += 10;
	return r;
}

int dist2(char c, int rem){
	int r = 7-(c-'0');
	if(r < 0) r += 10;
	if(c != '8'){
		return r + (r > rem);
	} else {
		return min(r + (r > rem), rem + 1);
	}
}

void solve(){

	string s; cin >> s;

	int mindif = dist(s[s.size()-1]), rem = 0;
	for(int i = s.size()-2; i >= 0; i--){
		rem += (s[i+1]-'0');
		if(i != s.size()-2) rem += 9*(s[i+1]-'0');
		mindif = min(dist2(s[i], rem), mindif);
	}
	cout << min(mindif, 7 + (s.size() == 1 && (s[0]-'0') < 7)) << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}