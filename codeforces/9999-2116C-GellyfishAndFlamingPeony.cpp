#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int mdc(int a,int b){
	if(a == 0) return b;
	return mdc(b%a, a);
}

void solve(){

	int n; cin >> n;
	vector<int> a (n+1, 0);
	int gggcd = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		gggcd = mdc(gggcd, a[i]);
	}

	int qtz = 0;
	for(int i = 1; i <= n; i++){
		a[i] /= gggcd;
		if(a[i] == 1) qtz++;
	}

	if(qtz > 0){
		cout << n - qtz << "\n";
		return;
	}

	vector<int> qt (5001, 5001);
	qt[1] = 0;
	for(int x = 2; x <= 5000; x++){
		for(int i = 1; i <= n; i++){
			int r = mdc(x,a[i]);
			qt[x] = min(qt[x],qt[r]+1);
		}
	}

	int mini = 50001;
	for(int i = 1; i <= n; i++){
		mini = min(qt[a[i]],mini);
	}
	cout << n-1 + mini << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}