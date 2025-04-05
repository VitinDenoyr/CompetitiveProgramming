//https://codeforces.com/contest/2055/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	ll n,m; cin >> n >> m;
	string s; cin >> s;
	vector<vector<ll>> a (n+1, vector<ll>(m+1, 0));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}

	int l = 1, c = 1;
	s += 'D'; // Facilitar último caractere
	for(char ch : s){
		if(ch == 'D'){
			for(int j = 1; j <= m; j++){
				if(j == c) continue;
				a[l][c] -= (ll)a[l][j];
			}
			l++;
		} else {
			for(int i = 1; i <= n; i++){
				if(i == l) continue;
				a[l][c] -= (ll)a[i][c];
			}
			c++;
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << a[i][j] << " \n"[j == m];
		}
	}
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}