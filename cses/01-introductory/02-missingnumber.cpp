#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ll n, s=0;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for(ll i = 0; i < n-1; i++){
		ll k;
		cin >> k;
		s += k;
	}
	cout << n*(n+1)/2 - s << "\n";

	return 0;
}