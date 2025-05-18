//https://codeforces.com/gym/105327/problem/L
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define p pair<ll,string>

int main(){

	ll n; cin >> n;
	vector<ll> a (n+1, 0); ll sum = 0;
	string s0 = "";
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
		s0 += "0";
	}
	if(sum%2 == 1){
		cout << -1 << "\n";
		return 0;
	}
	ll obj = sum/2;

	ll sm = 0;
	vector<p> dp (obj+1, {0,""}); dp[0] = {1, s0};
	for(ll j = 1; j <= n; j++){
		sm += a[j];
		for(ll i = min(sm,obj); i >= a[j]; i--){
			if(dp[i - a[j]].first != 0){
				dp[i] = dp[i-a[j]];
				(dp[i].second)[j-1] = '1';
			}
		}
	}
	if(dp[obj].first == 0){
		cout << -1 << "\n";
	} else {
		vector<ll> v, w;
		for(ll i = 1; i <= n; i++){
			if((dp[obj].second)[i-1] == '1'){
				v.push_back(a[i]);
			} else {
				w.push_back(a[i]);
			}
		}

		vector<ll> r;
		ll a = 0, b = 0;
		for(ll i = 1; i <= n; i++){
			if(a <= b){
				r.push_back(v[v.size()-1]);
				a += v[v.size()-1];
				v.pop_back();
			} else {
				r.push_back(w[w.size()-1]);
				b += w[w.size()-1];
				w.pop_back();
			}
		}

		for(ll i = 0; i < r.size(); i++){
			cout << r[i] << " \n"[i==(r.size()-1)];
		}
	}

	return 0;

}