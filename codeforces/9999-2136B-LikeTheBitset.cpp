//https://codeforces.com/contest/2136/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n,k; cin >> n >> k;
	string s; cin >> s;
	vector<int> p (n+1, 0);

	bool resp = true;
	int qt = 0;
	for(int i = 0; i < k; i++){
		if(s[i] == '1') qt++;
	}
	if(qt == k){
		resp = false;
	}
	for(int i = k; i < n; i++){
		if(s[i] > s[i-k]){
			qt++;
			if(qt == k) resp = false;
		} else if(s[i] < s[i-k]){
			qt--;
		}
	}

	int maxi = n;
	for(int i = 1; i <= n; i++){
		if(s[i-1] == '0'){
			p[i] = maxi--;
		}
	}
	for(int i = 1; i <= n; i++){
		if(s[i-1] == '1'){
			p[i] = maxi--;
		}
	}

	if(!resp){
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for(int i = 1; i <= n; i++){
			cout << p[i] << " \n"[i==n];
		}
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}