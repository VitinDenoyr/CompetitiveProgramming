//https://codeforces.com/problemset/problem/2060/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){

	int n,k; cin >> n >> k;
	vector<int> v (n+1, 0);
	map<int,int> qt; int p = 0;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		qt[v[i]]++;
		if((qt[k - v[i]] > 0 && k != 2*v[i]) || (qt[k - v[i]] > 1 && k == 2*v[i])){
			qt[k - v[i]]--;
			qt[v[i]]--;
			p++;
		}
	}

	cout << p << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}