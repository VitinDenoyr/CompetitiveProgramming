//https://codeforces.com/problemset/problem/2008/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	int t; cin >> t;

	vector<ll> a = {0,1}; ll dif = 1, last = 1;
	while(last+dif <= 1000000000ll){
		a.push_back(last+dif);
		last += dif;
		dif++;
	}

	while(t--){
		int le,ri;
		cin >> le >> ri;

		int l = 1, r = min((ll)(ri-le+1), (ll)(a.size()-1));
		while(l != r){
			int mid = (l+r+1)/2;
			if(a[mid]+(le-1) > ri){
				r = mid-1;
			} else {
				l = mid;
			}
		}
		cout << l << "\n";
	}

	return 0;
}