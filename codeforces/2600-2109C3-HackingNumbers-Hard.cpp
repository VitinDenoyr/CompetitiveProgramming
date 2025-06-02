//https://codeforces.com/contest/2109/problem/C3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll d18 = 1000000000000000000ll;

void solve(){

	ll n,ans; cin >> n;

	cout << "mul 999999999" << endl;
	cin >> ans;
	cout << "digit" << endl;
	cin >> ans;
	if(n != 81){
		cout << "add " << (n - 81) << endl;
		cin >> ans;
	}
	cout << "!" << endl;
	cin >> ans;

}

int main(){

	ll t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}