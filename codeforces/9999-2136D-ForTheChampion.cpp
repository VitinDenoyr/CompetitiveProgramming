//https://codeforces.com/contest/2136/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<ll> x (n+1, 0), y (n+1, 0);

	ll sub_xy = -1000000000000000ll;
	ll sup_xy = -1000000000000000ll;

	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
		sub_xy = max(x[i]-y[i],sub_xy);
		sup_xy = max(x[i]+y[i],sup_xy);
	}

	ll resp = 0;
	for(int i = 1; i <= 2; i++){
		cout << "? U 1000000000" << endl;
		cin >> resp;
		cout << "? R 1000000000" << endl;
		cin >> resp;
	}

	ll sum = sup_xy + resp - 4ll*1000000000ll;

	for(int i = 1; i <= 4; i++){
		cout << "? D 1000000000" << endl;
		cin >> resp;
	}

	ll sub = sub_xy + resp - 4ll*1000000000ll;

	cout << "! " << (sum + sub)/2 << " " << (sum - sub)/2 << endl;

}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}