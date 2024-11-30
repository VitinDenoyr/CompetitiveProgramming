//https://codeforces.com/problemset/problem/1906/M
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ll n, maxy = 0, sum = 0; cin >> n;
	vector<ll> v (n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
		maxy = max(v[i],maxy);
		sum += v[i];
	}
	if(maxy >= 2*(sum - maxy)){
		cout << (sum - maxy) << "\n";
	} else {
		cout << sum/3 << "\n";
	}

	return 0;
}