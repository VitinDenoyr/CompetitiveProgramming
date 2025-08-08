#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	int resp = 0;
	for(int i = 1; i <= n; i++){
		int a; cin >> a;
		resp ^= (a%4);
	}

	if(resp == 0){
		cout << "second\n";
	} else {
		cout << "first\n";
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}