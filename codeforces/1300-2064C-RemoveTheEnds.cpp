//https://codeforces.com/problemset/problem/2064/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<int> a (n+1, 0);
	vector<ll> cumul (n+1, 0);
	stack<int> neg;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] < 0){
			neg.push(i);
			cumul[i] = cumul[i-1];
		} else {
			cumul[i] = cumul[i-1] + a[i];
		}
	}

	ll resp = cumul[n];
	ll s = 0;
	while(!neg.empty()){
		s += abs(a[neg.top()]);
		resp = max(resp, s + cumul[neg.top()-1]);
		neg.pop();
	}
	cout << resp << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}