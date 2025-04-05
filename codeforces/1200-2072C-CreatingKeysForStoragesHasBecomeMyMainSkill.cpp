//https://codeforces.com/contest/2072/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	ll n, x; cin >> n >> x;
	ll val = 0; //Não posso ter o 2^val
	for(int i = 0; i <= 30; i++){
		if((x&(1ll<<i)) == 0){
			val = i;
			break;
		}
	}

	ll accumOr = 0;
	for(int i = 1; i <= n-1; i++){
		cout << (i <= (1ll<<val) ? i-1 : x) << " ";
		if(i <= (1ll<<val)) accumOr |= (i-1);
	}
	if(((n-1) | accumOr) == x){
		cout << n-1 << "\n";
	} else {
		cout << x << "\n";
	}

}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}