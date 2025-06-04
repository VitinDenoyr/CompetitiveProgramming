#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<int> a (n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	ll k = 0;
	for(int i = n-1; i >= 1; i--){
		if(a[i] > a[i+1]){
			k += (a[i]+a[i+1]-1)/a[i+1] - 1ll;
			a[i] /= ((a[i]+a[i+1]-1)/a[i+1]);
		}
	}
	cout << k << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}