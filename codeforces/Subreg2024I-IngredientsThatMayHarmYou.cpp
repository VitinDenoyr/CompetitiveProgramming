//https://codeforces.com/gym/105327/problem/I
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxi = 1000000;
const ll mod = 1000000007;

ll fexpo(ll a, ll b){
	ll res = 1;
	while(b > 0){
		if(b%2){
			res = (res * a)%mod;
			b--;
		} else {
			a = (a*a)%mod;
			b /= 2;
		}
	}
	return res;
}
 
int main(){
 
	int n; cin >> n;
	vector<int> f (n+1, 0);
	vector<int> qt (maxi+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> f[i];
		qt[f[i]]++;
	}

	vector<int> gpDiv (maxi+1, 1);
	for(int i = 2; i <= maxi; i++){
		if(gpDiv[i] == 1){
			for(int j = i; j <= maxi; j += i){
				gpDiv[j] = i;
			}
		}
	}

	vector<int> qtMult (maxi+1, 0);
	for(int i = 2; i <= maxi; i++){
		for(int j = i; j <= maxi; j += i){
			qtMult[i] += qt[j];
		}
	}

	int q; cin >> q;
	for(int _ = 1; _ <= q; _++){
		int	allergy; cin >> allergy;
		if(allergy == 1){
			cout << fexpo(2,n) << "\n";
			continue;
		}

		vector<int> primes;
		while(allergy > 1){
			if(primes.empty() || gpDiv[allergy] != primes[primes.size()-1]) primes.push_back(gpDiv[allergy]);
			allergy /= gpDiv[allergy];
		}

		ll tot = 0;
		for(int mask = ((1ll<<primes.size()) - 1); mask >= 1; mask--){
			ll multpl = 1, sign = -1;
			for(int i = 0; i < primes.size(); i++){
				if((mask & (1ll<<i)) != 0){
					multpl *= primes[i];
					sign *= -1;
				}
			}
			tot += qtMult[multpl]*sign;
		}
		cout << fexpo(2,n - tot) << "\n";

	}

	return 0;
}