#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007ll;

ll fexpo(ll a, ll b, ll m){
	if(a == 0 && b == 0) return 1;
	ll res = 1;
	while(b > 0){
		if(b%2){
			res = (res*a)%m;
			b--;
		} else {
			a = (a*a)%m;
			b /= 2;
		}
	}
	return res;
}

int main(){

	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		int a,b,c; cin >> a >> b >> c;
		cout << fexpo(a,fexpo(b,c,mod-1),mod) << "\n";
	}

	return 0;
}