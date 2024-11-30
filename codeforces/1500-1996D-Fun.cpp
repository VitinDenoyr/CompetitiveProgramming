//https://codeforces.com/contest/1996/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define printvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl

int main(){
	int t; cin >> t;
	for(int it = 0; it < t; it++){
		ll n,x; cin >> n >> x;
		ll r = 0;
		for(ll a = 1; a <= x-2; a++){
			for(ll b = 1; b <= min(n/a , x-a-1); b++){
				r += min(x-a-b, (n-a*b)/(a+b));
			}
		}

		cout << r << "\n";
	}
	

	return 0;
}