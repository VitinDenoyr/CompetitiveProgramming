//https://codeforces.com/contest/2109/problem/C2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll d18 = 1000000000000000000ll;

void solve(){

	ll n,ans; cin >> n;

	cout << "mul 9" << endl;
	cin >> ans;

	cout << "digit" << endl;
	cin >> ans;

	cout << "digit" << endl;
	cin >> ans;

	if(n != 9){
		cout << "add " << n-9 << endl;
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