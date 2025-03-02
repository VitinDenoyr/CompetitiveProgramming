//https://codeforces.com/problemset/problem/2057/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n,k; cin >> n >> k;
	vector<int> a (n+1, 0);
	map<int,int> freq;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		freq[a[i]]++;
	}

	vector<pii> v;
	for(pii p : freq){
		v.push_back({p.second,p.first});
	}
	sort(v.begin(),v.end());

	int op = v.size();
	for(int i = 0; i < v.size(); i++){
		if(k >= v[i].first && op > 1){
			k -= v[i].first;
			op--;
		} else {
			break;
		}
	}

	cout << op << "\n";

}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}