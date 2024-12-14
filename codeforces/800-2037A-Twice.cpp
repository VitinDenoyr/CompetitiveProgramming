//https://codeforces.com/contest/2037/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	int n; cin >> n;
	vector<int> a (n+1, 0);
	map<int,int> qt;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		qt[a[i]]++;
	}
	int sum = 0;
	for(auto k : qt){
		sum += (k.second/2);
	}
	cout << sum << "\n";
}

int main(){

	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}