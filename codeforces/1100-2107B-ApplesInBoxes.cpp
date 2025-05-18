//https://codeforces.com/contest/2107/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n,k; cin >> n >> k;
	vector<ll> a (n+1, 0);
	ll tomLose = 0;
	ll maxi = 0; ll mini = 1000000001;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		tomLose += a[i];
		maxi = max(a[i],maxi);
		mini = min(a[i],mini);
	}
	int qtmaxi = 0, qtmini = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == maxi) qtmaxi++;
		if(a[i] == mini) qtmini++;
	}

	tomLose = (tomLose+1)%2;
	if(maxi - mini > k+1 || maxi - mini == k+1 && qtmaxi > 1){
		cout << "Jerry\n";
		return;
	} else {
		if(tomLose){
			cout << "Jerry\n";
			return;
		} else {
			cout << "Tom\n";
			return;
		}
		return;
	}
}

int32_t main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}