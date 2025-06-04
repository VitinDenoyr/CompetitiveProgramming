//https://codeforces.com/contest/2111/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

bool rev(ll a, ll b){
	return a > b;
}

void solve(){

	ll n,m; cin >> n >> m;
	vector<ll> a (m+1, 0);
	vector<ll> c, d;
	for(int i = 1; i <= m; i++){
		cin >> a[i];
		c.push_back(a[i]);
		d.push_back(a[i]);
	}

	sort(c.begin(),c.end());
	sort(d.begin(),d.end(),rev);
	for(int i = 0; i < n; i++){
		if(i%2 == 0){
			for(int j = 0; j < 6; j++){
				if(j%2 == 1){
					cout << c[i/2] << " \n"[j==5];
				} else {
					cout << d[i/2] << " \n"[j==5];
				}
			}
		} else {
			for(int j = 0; j < 6; j++){
				if(j%2 == 1){
					cout << d[i/2] << " \n"[j==5];
				} else {
					cout << c[i/2] << " \n"[j==5];
				}
			}
		}
	}

}

int32_t main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}


//1 2 3 .
//. 3 2 1