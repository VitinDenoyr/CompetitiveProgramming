//https://codeforces.com/problemset/problem/2106/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

void solve(){

	ll n; cin >> n;
	string s; cin >> s;
	s += (char)('0'+('1' - s[s.length()-1]));

	vector<vector<ll>> block;

	ll first = 0;
	for(ll c = 1; c <= n; c++){
		if(s[c] != s[c-1]){
			if(s[c] == '0'){
				block.push_back({0,c-first});
				if(c != n) first = c;
			} else {
				block.push_back({1,(c*(c-1))/2 - (first*(first-1))/2,(c-first)*(n-1) - ((c*(c-1))/2 - (first*(first-1))/2)});
				if(c != n) first = c;
			}
		}
	}

	for(ll i = 0; i < block.size(); i++){
		if(block[i][0] == 0){
			if(i == 0 && first != 0){
				block[i+1][1]++;
			} else if(i == block.size()-1 && first != 0){
				block[i-1][2]++;
			} else if(i > 0 && i < block.size()-1){
				if(block[i][1] == 1){
					block[i-1][2] += block[i+1][1] + 1;
				} else {
					block[i+1][1]++;
					block[i-1][2]++;
				}
			}
		}
	}

	ll resp = 0;
	for(ll i = 0; i < block.size(); i++){
		if(block[i][0] == 1){
			resp = max(block[i][1], max(block[i][2], resp));
		}
	}
	if(block[0][0] == 0 && first == 0){
		resp = 1;
	}

	cout << resp << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}