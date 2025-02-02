//https://codeforces.com/problemset/problem/2036/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	int n,k; cin >> n >> k;
	vector<int> cost (k+1, 0), brand (k+1, 0);
	map<int,int> tot;
	for(int i = 1; i <= k; i++){
		cin >> brand[i] >> cost[i];
		tot[brand[i]] += cost[i];
	}
	vector<int> shelves;
	for(auto p : tot){
		shelves.push_back(p.second);
	}
	sort(shelves.begin(),shelves.end());
	int resp = 0, id = shelves.size()-1, esc = 0;
	for(int j = id; j >= 0; j--){
		resp += shelves[j];
		shelves.pop_back();
		esc++;
		if(esc == n) break;
	}
	cout << resp << "\n";
}

int main(){

	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}