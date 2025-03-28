//https://codeforces.com/problemset/problem/2085/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

void solve(){

	ll n,k; cin >> n >> k;
	vector<ll> d (n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> d[i];
	}

	multiset<pii> s;
	for(ll i = n; i >= 1; i--){
		if (((n+1-i)%(k+1)) == 0){
			s.insert({0ll,0ll});
		}
		if(!s.empty() && ((*s.begin()).first < d[i])){
			s.erase(s.begin());
			s.insert({d[i],i});
		}
	}
	ll resp = 0;
	for(pii p : s){
		resp += p.first;
	}
	cout << resp << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}