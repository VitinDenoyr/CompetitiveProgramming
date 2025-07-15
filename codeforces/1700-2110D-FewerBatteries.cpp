//https://codeforces.com/problemset/problem/2110/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>

void solve(){

	int n,m; cin >> n >> m;
	vector<ll> b (n+1, 0);
	ll sbat = 0;
	for(int i = 1; i <= n; i++){
		cin >> b[i];
		sbat += b[i];
	}

	vector<vector<pll>> pass (n+1, vector<pll>());

	vector<int> s (m+1, 0), t (m+1, 0), w (m+1, 0);
	for(int i = 1; i <= m; i++){
		cin >> s[i] >> t[i] >> w[i];
		pass[s[i]].push_back({t[i],w[i]});
	}

	ll l = 1, r = sbat+1;
	while(l < r){
		ll mid = (l+r)/2;
		vector<ll> qt (n+1, 0);
		qt[1] = min(mid,b[1]);
		for(int i = 1; i < n; i++){
			for(pll op : pass[i]){
				if(qt[i] >= op.second){
					//cout << op.first << ": " << qt[i] + b[op.first] << "\n";
					qt[op.first] = min(max(qt[i] + b[op.first], qt[op.first]),mid);
				}
			}
		}
		if(qt[n] > 0){
			r = mid;
		} else {
			l = mid+1;
		}
	}
	if(l == sbat+1){
		cout << -1 << "\n";
	} else {
		cout << l << "\n";
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