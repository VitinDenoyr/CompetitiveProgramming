//https://codeforces.com/problemset/problem/1999/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define MAXN 200005
ll fat[MAXN] = {1};

ll fexp(ll a, ll b){
	ll res = 1;
	while(b > 0){
		if(b%2 == 1){
			res *= a;
			res %= mod;
			b--;
		} else {
			a *= a;
			a %= mod;
			b >>= 1;
		}
	}
	return res%mod;
}

ll choose(ll x, ll y){
	if(y > x) return 0;
	ll p1 = (fexp(fat[y],mod-2)*fexp(fat[x-y],mod-2))%mod;
	return ((fat[x]*p1)%mod);
}

int main(){

	for(int i = 1; i < MAXN; i++) fat[i] = (i*fat[i-1])%mod;
	
	int t; cin >> t;
	for(int it = 0; it < t; it++){
		ll n,k; ll qt[2] = {0,0};
		cin >> n >> k;
		for(int i = 0; i < n; i++){
			int a; cin >> a; qt[a]++;
		}
		ll tot = 0;
		for(int e1 = (k+1)/2; e1 <= k; e1++){
			tot += (choose(qt[1],e1)*choose(qt[0],k - e1))%mod;
			tot %= mod;
		}
		cout << tot << endl;
	}

	return 0;
}