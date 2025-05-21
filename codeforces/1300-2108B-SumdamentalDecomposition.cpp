#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n,x; cin >> n >> x;
	int qt = 0;
	for(int b = 0; b < 30; b++){
		if((x & (1<<b)) != 0){
			qt++;
		}
	}

	if(qt >= n){
		cout << x << "\n";
		return;
	}

	if(x == 1){
		cout << n + (n%2 == 0)*(3) << "\n";
		return;
	} else if(x == 0){
		if(n == 1){
			cout << -1 << "\n";
			return;
		}
		cout << n + (n%2 == 1)*(3) << "\n";
		return;
	}
	cout << x + ((n-qt)+(n-qt)%2) << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}