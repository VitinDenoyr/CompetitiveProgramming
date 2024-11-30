//https://codeforces.com/problemset/problem/2008/G
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int mdc(int a, int b){
	if(b == 0) return a;
	return mdc(b,a%b);
}

int main(){

	int t; cin >> t;
	while(t--){
		int n,k; cin >> n >> k;
		vector<int> v(n+1);
		int tmdc = 0;
		for(int i = 1; i <= n; i++){
			cin >> v[i];
			tmdc = mdc(v[i],tmdc);
		}
		if(n == 1){
			cout << (k-1) + (v[1] <= k-1) << "\n";
		} else {
			if(tmdc == 1){
				cout << (k-1) + n << "\n";
			} else {
				cout << (k-1) + min((k+tmdc-2)/(tmdc-1),n) << "\n";
			}
		}
	}

	return 0;
}