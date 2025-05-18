//https://codeforces.com/contest/2108/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<int> a (n+2, 0);

	int qt = 0, state = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != a[i-1]){
			if(a[i] > a[i-1]) state = 0;
			qt += (state);
			state = (a[i] > a[i-1]);
		}
	}
	qt += state;

	cout << qt << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}