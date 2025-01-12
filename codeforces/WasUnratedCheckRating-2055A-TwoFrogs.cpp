#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	int n,a,b; cin >> n >> a >> b;
	cout << ((b-a)%2 != 0 ? "NO\n" : "YES\n");
}

int main(){

	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}