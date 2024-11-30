//https://codeforces.com/contest/1996/problem/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define prllvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl
#define MAXN 200005
#define mod 1000000007

int main(){

	ll t; cin >> t;
	for(ll it = 0; it < t; it++){
		string s; cin >> s;

		ll resp = 0, sz = s.length();
		ll dif[2*sz+1] = {0}, qd[2] = {0,0};
		ll lt[2*sz+1] = {0};
		lt[sz] = 1;

		for(ll i = 1; i <= s.length(); i++){
			qd[(ll)(s[i-1] - '0')]++;
			dif[i] = qd[1] - qd[0] + sz;
			resp += (sz - i + 1)*(lt[dif[i]])%mod;
			resp %= mod;
			lt[dif[i]] += i+1;
			lt[dif[i]] %= mod;
		}

		cout << resp << "\n";
	}

	return 0;
}