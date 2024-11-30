//https://codeforces.com/problemset/problem/1995/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005ll
#define BIG 1000001ll
 
ll tryExp(ll a, ll b){
	ll resp = 1;
	while(b > 0){
		if(b%2 == 1){
			resp *= a;
			if(resp >= BIG) return BIG;
			b--;
		} else {
			a *= a;
			b = b/2;
			if(a >= BIG) return BIG; 
		}
	}
	return resp;
}
 
ll cnt(ll a, ll b){
	ll r = 0;
	if(a > b){
		while(tryExp(b,(1<<r)) < a){
			r++;
		}
		return -r;
	} else {
		while(tryExp(a,(1<<r+1)) <= b){
			r++;
		}
	}
	return r;
}
 
int main(){
 
	int t; cin >> t;
	while(t--){
		ll n; cin >> n;
		vector<int> v (n+1, 0);
		vector<int> c (n+1, 0);
		for(int i = 1; i <= n; i++){
			cin >> v[i];
		}
		ll resp = 0;
		for(int i = 2; i <= n; i++){
			if(v[i-1] > v[i] && v[i] == 1){
				resp = -1; break;
			}
			if(v[i-1] == 1) continue;
			ll hA = c[i-1], hB = cnt(v[i-1],v[i]);
 			c[i] = max(0ll, hA - hB);
			resp += c[i];
		}
		cout << resp << "\n";
	}
 
	return 0;
}