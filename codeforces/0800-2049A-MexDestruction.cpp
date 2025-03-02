//https://codeforces.com/problemset/problem/2049/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<int> a (n+1,0); int difZero = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 0 && a[i-1] == 0) difZero++;
	}

	if(difZero == 0){
		cout << 0 << "\n";
		return;
	} else if(difZero == 1){
		cout << 1 << "\n";
		return;
	} else {
		cout << 2 << "\n";
		return;
	}
}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}