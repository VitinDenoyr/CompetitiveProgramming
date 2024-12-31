#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007ll;

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
	return res;
}

int main(){

	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		int a,b; cin >> a >> b;
		cout << fexpo(a,b) << "\n";
	}

	return 0;
}