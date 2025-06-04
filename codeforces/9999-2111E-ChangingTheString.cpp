//https://codeforces.com/contest/2111/problem/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<char,char>

void solve(){

	int n,qq; cin >> n >> qq;
	string s; cin >> s;

	vector<vector<set<int>>> q (3, vector<set<int>> (3, set<int>()));

	for(int iq = 1; iq <= qq; iq++){
		char a,b; cin >> a >> b;
		if(a == 'a' || a == b) continue;
		q[a-'a'][b-'a'].insert(iq);
	}
	q[1][0].insert(qq+2);
	q[2][0].insert(qq+2);
	q[1][2].insert(qq+2);
	q[2][1].insert(qq+2);

	for(int i = 0; i < n; i++){
		if(s[i] == 'a') continue;
		if(s[i] == 'b'){
			if((*q[1][0].begin()) != qq+2){
				q[1][0].erase(q[1][0].begin());
				s[i] = 'a';
			} else if((*q[1][2].begin()) != qq+2 && (*q[2][0].upper_bound(*q[1][2].begin())) != qq+2){
				q[2][0].erase(q[2][0].upper_bound(*q[1][2].begin()));
				q[1][2].erase(q[1][2].begin());
				s[i] = 'a';
			}
		} else {
			if((*q[2][0].begin()) != qq+2){
				q[2][0].erase(q[2][0].begin());
				s[i] = 'a';
			} else if((*q[2][1].begin()) != qq+2 && (*q[1][0].upper_bound(*q[2][1].begin())) != qq+2){
				q[1][0].erase(q[1][0].upper_bound(*q[2][1].begin()));
				q[2][1].erase(q[2][1].begin());
				s[i] = 'a';
			} else if((*q[2][1].begin()) != qq+2){
				q[2][1].erase(q[2][1].begin());
				s[i] = 'b';
			}
		}
	}
	cout << s << "\n";

}

int32_t main(){

	//ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}