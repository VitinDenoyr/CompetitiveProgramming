//https://codeforces.com/problemset/problem/2008/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007ll;

ll fastexpo(ll a, ll b){
	ll ans = 1;
	while(b > 0){
		if(b%2 == 0){
			a = ((a%mod)*(a%mod))%mod;
			b /= 2;
		} else {
			ans = ((ans%mod)*(a%mod))%mod;
			b--;
		}
	}
	return ans%mod;
}

ll mdc(ll a, ll b){
	if(b == 0) return a;
	return mdc(b,a%b);
}

int main(){

	int t; cin >> t;
	while(t--){
		ll n; cin >> n;
		vector<ll> v(n+1,0);
		vector<ll> sum(n+1,0);

		for(int i = 1; i <= n; i++){
			cin >> v[i];
			sum[i] = sum[i-1] + v[i];
		}

		ll num = 0;
		ll den = (n*(n-1))/2ll;
		for(int i = 1; i <= n; i++){
			num = (num + (v[i]*((sum[i-1])%mod))%mod)%mod;
		}

		ll r = fastexpo(den%mod,mod-2)%mod;
		r = (r*(num%mod))%mod;
		cout << r << "\n";
	}

	return 0;
}