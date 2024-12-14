//https://codeforces.com/contest/2037/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	int k; cin >> k;
	vector<int> ks (k+1, 0);
	map<int,int> mp;

	for(int i = 1; i <= k; i++){
		cin >> ks[i];
		mp[ks[i]]++;
	}

	int nxm = k-2;
	for(int i = 1; i <= nxm; i++){
		if(nxm%i != 0) continue;
		int j = nxm / i;
		if(mp.find(i) == mp.end() || mp.find(j) == mp.end()) continue;
		cout << i << " " << j << "\n";
		break;
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}