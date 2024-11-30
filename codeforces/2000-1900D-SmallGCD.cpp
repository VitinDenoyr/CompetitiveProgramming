//https://codeforces.com/contest/1900/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXV 100005

ll mdc(ll a, ll b){
	if(a == 0) return b;
	return mdc(b%a, a);
	cout << ":3\n";
}

int main(){

	ll t; cin >> t;
	while(t--){
		ll n, mv = 0; cin >> n;
		vector<ll> v (n), mult (MAXV,0), tot (MAXV,0);
		for(ll i = 0; i < n; i++){
			cin >> v[i];
			mv = max(v[i],mv);
		}
		sort(v.begin(),v.end());

		for(ll i = 0; i < n-1; i++){
			for(ll m = 1; m*m <= v[i]; m++){
				if(v[i]%m == 0){
					tot[m] += (mult[m])*(n-1-i);
					mult[m]++;
					if(m*m < v[i]){
						tot[v[i]/m] += (mult[v[i]/m])*(n-1-i);
						mult[v[i]/m]++;
					}
				}
			}
		}

		ll sum = 0;
		for(ll v = mv; v >= 1; v--){
			if(mult[v] < 2) continue;
			for(ll k = v*2; k <= mv; k += v){
				tot[v] -= tot[k];
			}
			sum += tot[v]*v;
		}
		cout << sum << "\n";
	}

	return 0;
}