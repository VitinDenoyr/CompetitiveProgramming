//https://codeforces.com/problemset/problem/2061/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>

void solve(){

	int n; cin >> n;
	vector<ll> stick (n+1, 0);

	for(int i = 1; i <= n; i++){
		cin >> stick[i];
	}

	sort(stick.begin(), stick.end());
	int v = 0, p = 0;
	for(int i = 1; i < n; i++){
		if(stick[i] == stick[i+1]){
			p = i; v = stick[i];
		}
	}
	if(v == 0){
		cout << -1 << "\n";
		return;
	}
	stick.erase(stick.begin() + p);
	stick.erase(stick.begin() + p);

	for(int i = 1; i < n-2; i++){
		if(stick[i+1] < 2ll*v + stick[i]){
			cout << v << " " << v << " " << stick[i] << " " << stick[i+1] << "\n";
			return;
		}
	}
	cout << -1 << "\n";
}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}