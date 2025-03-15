#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const ll mod = 1000000007;

ll fexpo(ll a, ll b){
	ll res = 1;
	while(b > 0){
		if(b%2){
			res = (res*a)%mod;
			b--;
		} else {
			a = (a*a)%mod;
			b /= 2;
		}
	}
	return res%mod;
}

int main(){

	int n; cin >> n;
	if(n%2){
		cout << 0 << "\n";
		return 0;
	}
	n /= 2;
	
	//Catalan(N) -> (2N N) - (2N N+1)
	vector<ll> fac (2*n+1, 1);
	ll prod = 1;
	for(int i = 2; i <= 2*n; i++){
		fac[i] = (i*fac[i-1])%mod;
		if(i > n) prod = (prod * i)%mod;
	}
	
	cout << (((prod * fexpo(fac[n],mod-2))%mod - ((prod * n)%mod * fexpo(fac[n+1],mod-2))%mod)%mod + mod)%mod << "\n";
	
	return 0;

}