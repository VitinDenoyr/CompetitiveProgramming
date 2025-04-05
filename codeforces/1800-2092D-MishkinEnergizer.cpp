//https://codeforces.com/contest/2092/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){

	int n; cin >> n;
	string s; cin >> s;
	vector<int> op;
	
	int piv = -1;
	for(int i = 0; i < n-1; i++){
		if(s[i] == s[i+1]) continue;
		int cop = op.size();
		for(int j = 0; j < i-piv; j++){
			op.push_back(i+1+cop); op.push_back(i+1+cop);
		}
		piv = i;
	}

	if(piv == -1){
		cout << -1 << "\n";
		return;
	}

	int rem = (n-1)-piv;
	for(int i = 1; i <= 2*rem; i++){
		op.push_back(n-rem+op.size());
	}

	cout << op.size() << "\n";
	for(int x : op){
		cout << x << "\n";
	}

}

int main(){

	//ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}