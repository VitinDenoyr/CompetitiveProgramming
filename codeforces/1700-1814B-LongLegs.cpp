//https://codeforces.com/problemset/problem/1814/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define printvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl

int main(){

	ll t; cin >> t;
	for(int i = 0; i < t; i++){
		ll a,b; cin >> a >> b;
		if(a > b) swap(a,b);
		ll k = 1, mx = 2000000000ll;
		ll tlim = min(b,300000ll);
		while(tlim--){
			mx = min((k-1) + (b+k-1)/(k) + (a+k-1)/(k),mx);
			k++;
		}
		cout << mx << "\n"; 
	}

	return 0;
}