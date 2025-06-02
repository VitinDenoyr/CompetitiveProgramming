//https://codeforces.com/problemset/problem/2114/G
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	ll n,k,spend; cin >> n >> k;
	spend = k - n;
	vector<ll> a (n+1, 0);
	vector<ll> exp (n+1, 0);
	vector<ll> stalkerbuxa (n+1, 0);
	ll ss = 0, ms = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		for(int z = 1; z <= 30; z++){
			if((a[i] % (1ll<<z)) != 0){
				break;
			}
			exp[i]++;
		}

		if(i > 1){
			if(a[i] > a[i-1] && a[i]%a[i-1] == 0 && ((a[i]/a[i-1])&(-(a[i]/a[i-1]))) == (a[i]/a[i-1])){
				stalkerbuxa[i] = (1ll<<(exp[i])) - (1ll<<(exp[i-1]+1)) + 1;
			} else {
				stalkerbuxa[i] = (1ll<<exp[i]);
			}
		} else {
			stalkerbuxa[i] = (1ll<<exp[i]);
		}
		ss += stalkerbuxa[i];
	}
	ms = ss;

	for(int i = 2; i <= n; i++){
		ss -= stalkerbuxa[i];
		ss -= stalkerbuxa[i-1];
		if(a[i-1] > a[i] && a[i-1]%a[i] == 0 && ((a[i-1]/a[i])&(-(a[i-1]/a[i]))) == (a[i-1]/a[i])){
			stalkerbuxa[i-1] = (1ll<<(exp[i-1])) - (1ll<<(exp[i]+1)) + 1;
		} else {
			stalkerbuxa[i-1] = (1ll<<exp[i-1]);
		}
		stalkerbuxa[i] = (1ll<<exp[i]);
		ss += stalkerbuxa[i];
		ss += stalkerbuxa[i-1];
		ms = max(ms, ss);
	}

	cout << (ms >= k ? "Yes" : "No") << "\n";

}

int main(){

	int tt; cin >> tt;
	while (tt--){
		solve();
	}
	return 0;

}