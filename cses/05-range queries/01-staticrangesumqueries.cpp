#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ll n,q;
	cin >> n >> q;
	ll sum[n+1] = {0};
	for(ll i = 0; i < n; i++){
		ll a; cin >> a;
		sum[i+1] = sum[i] + a;
	}
	for(ll i = 0; i < q; i++){
		ll a,b; cin >> a >> b;
		cout << sum[b] - sum[a-1] << "\n";
	}

	return 0;
}