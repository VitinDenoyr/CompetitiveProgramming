//https://codeforces.com/problemset/problem/2081/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
const ll mod = 1000000007;

ll fexpo(ll a, ll b){
	ll r = 1;
	while(b > 0){
		if(b%2){
			r = (r * a)%mod;
			b --;
		} else {
			a = (a * a)%mod;
			b /= 2;
		}
	}
	return r;
}

void solve(){

	ll n; cin >> n;
	vector<ll> p (n+2, 0), a (n+1, 0);
	for(ll i = 1; i <= n; i++){
		char c; cin >> c;
		a[i] = (c == '1');
	}
	if(n == 1){
		cout << 0 << "\n";
		return;
	}

	for(ll i = n; i >= 2; i--){
		p[i] = (p[i+1]*(a[i]+1))%mod + ((((fexpo(2,n-i) - p[i+1])%mod + mod)%mod)*(a[i]))%mod;
	}

	cout << (((p[2] + (fexpo(2, n-1)*(n-1))%mod)%mod * fexpo(fexpo(2, n-1),mod-2))%mod)%mod << "\n"; 
	
	//P(N) = probabilidade de, no N-ésimo movimento subir pra frente.

	//110
	//P(3) = 0
	//P(2) = 1/2 + (1/2)*P(3) = 1/2
	//2 + 1/2 

	//100
	//P(3) = 0
	//P(2) = 0
	//2 + 0

	//1101001011
	//P(10) = 1/2
	//P(9) = (1 - P(10))*(1/2 se for 1, 0/2 se for 0) + P(10)*(2/2 se for 1, 1/2 se for 0) = 3/4
	//P(8) = P(9)*(1/2) = 3/8
	//P(7) = 5/16 + 6/16 = 11/16
	//P(6) = 11/32
	//P(5) = 11/64
	//P(4) = 22/128 + (53/128) = 75/128
	//P(3) = 75/256
	//P(2) = (181/512) + (150/512) = 331/512

	//9 + 331/512
	//(9*512+331)/512    4.939 

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}