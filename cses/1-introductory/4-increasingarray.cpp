#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll maxl(ll a, ll b){
	if(a > b) return a;
	return b;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll n;
	cin >> n;
	ll last = -1, k, resp = 0;
	for(ll i = 0; i < n; i++){
		cin >> k;
		resp += maxl(last - k, 0);
		last = maxl(last, k);
	}
	cout << resp;

	return 0;
}