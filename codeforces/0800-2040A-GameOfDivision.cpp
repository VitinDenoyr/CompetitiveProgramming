//https://codeforces.com/contest/2040/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	int n,k; cin >> n >> k;
	vector<int> v (n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}
	bool can = false; int ch = -1;
	for(int a = 1; a <= n; a++){
		can = true;
		for(int b = 1; b <= n; b++){
			if(a == b) continue;
			if(abs(v[a] - v[b])%k == 0){
				can = false;
				break;
			}
		}
		if(can == true){
			ch = a;
			break;
		}
	}
	if(ch > 0){
		cout << "YES\n" << ch << "\n";
	} else {
		cout << "NO\n";
	}
}

int main(){

	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}