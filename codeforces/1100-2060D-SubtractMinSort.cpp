//https://codeforces.com/problemset/problem/2060/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){

	int n; cin >> n;
	vector<int> a(n+1, 0);

	int ziko = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i > 1){
			if(a[i] < a[i-1]){
				ziko = i-1;
			}
		}
	}

	if(ziko == 0){
		cout << "YES\n";
		return;
	}

	for(int i = 1; i < ziko; i++){
		//a[i] tem que ser 0
		if(a[i] <= a[i+1]){
			a[i+1] -= a[i];
			a[i] = 0;
		} else {
			cout << "NO\n";
			return;
		}
	}

	if(a[ziko] > a[ziko+1]){
		cout << "NO\n";
		return;
	} else {
		cout << "YES\n";
		return;
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