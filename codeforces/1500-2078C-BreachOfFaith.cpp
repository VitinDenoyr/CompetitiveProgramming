//https://codeforces.com/problemset/problem/2077/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>

void solve(){

	ll n; cin >> n;
	vector<ll> a (2*n+1, 0); ll sum = 0;
	for(ll i = 1; i <= 2*n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	ll a2 = a[2*n] + a[2*n-1]; //a1 + a3       (maior e segundo maior)
	for(int i = 1; i <= n-1; i++){
		a2 += a[2*n-2*i] - a[2*n-2*i-1]; //a5 - a4 + ... (terceiro maior em diante)
	}
	cout << a[2*n] << " " << a2 << " " << a[2*n-1] << " \n"[n==1];
	for(int i = 1; i <= n-1; i++){
		cout << a[2*n-2*i-1] << " " << a[2*n-2*i] << " \n"[i==(n-1)];
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}


//a2 = a1 + a3 + ... + a2n-1 - a4 - a6 ... - a2n
//a2 = a1 + a3 + (a5 - a4) + (a7 - a6) + ... + (a2n+1 - a2n)


//se n = 1, então 
