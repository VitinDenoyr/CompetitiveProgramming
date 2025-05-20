//https://codeforces.com/problemset/problem/2104/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n,k; cin >> n >> k;
	string s; cin >> s;
	vector<vector<int>> dps (n+2, vector<int>(26, n+2));
	vector<int> qt (26, 0);
	vector<int> mini (n+1, n+1);
	mini[n] = 0;
	for(int i = n-1; i >= 0; i--){
		qt[s[i]-'a']++;
		for(int j = 0; j < k; j++){
			dps[i][j] = dps[i+1][j];
			mini[i] = min(qt[j],mini[i]);
		}
		if(mini[i] > mini[i+1]){
			for(int j = 0; j < k; j++){
				qt[j] = mini[i];
			}
		}
		dps[i][s[i]-'a'] = i;
	}

	int q; cin >> q;
	for(int iq = 1; iq <= q; iq++){
		string x; cin >> x;
		int z = -1, resp = 0;
		for(int i = 0; i < x.length(); i++){
			z = dps[z+1][x[i]-'a'];
			if(z >= n) break;
		}
		if(z < n){
			resp += mini[z+1]+1;
		}

		cout << resp << "\n";
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	solve();

	return 0;

}