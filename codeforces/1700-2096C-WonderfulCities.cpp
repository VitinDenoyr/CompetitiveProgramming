#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const ll INF = 10000000000000008ll;

void solve(){

	int n; cin >> n;
	vector<vector<int>> a (n+1, vector<int> (n+1, 0));
	vector<ll> r (n+1, 0), c (n+1, 0);
	vector<vector<ll>> dprow (n+1, vector<ll>(2, INF));
	vector<vector<ll>> dpcol (n+1, vector<ll>(2, INF));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++) cin >> r[i];
	for(int i = 1; i <= n; i++) cin >> c[i];

	dprow[1][0] = 0; dprow[1][1] = r[1];
	dpcol[1][0] = 0; dpcol[1][1] = c[1];

	for(int i = 2; i <= n; i++){
		bool v01 = true, v11 = true, v00 = true, v10 = true;
		for(int j = 1; j <= n; j++){
			if(a[i-1][j] == a[i][j]){
				v00 = false;
				v11 = false;
			} else if(a[i-1][j] == a[i][j]+1){
				v01 = false;
			} else if(a[i-1][j]+1 == a[i][j]){
				v10 = false;
			}
		}
		if(v00) dprow[i][0] = min(dprow[i-1][0], dprow[i][0]);
		if(v10) dprow[i][0] = min(dprow[i-1][1], dprow[i][0]);
		if(v01) dprow[i][1] = min(dprow[i-1][0] + r[i], dprow[i][1]);
		if(v11) dprow[i][1] = min(dprow[i-1][1] + r[i], dprow[i][1]);
	}

	for(int i = 2; i <= n; i++){
		bool v01 = true, v11 = true, v00 = true, v10 = true;
		for(int j = 1; j <= n; j++){
			if(a[j][i-1] == a[j][i]){
				v00 = false;
				v11 = false;
			} else if(a[j][i-1] == a[j][i]+1){
				v01 = false;
			} else if(a[j][i-1]+1 == a[j][i]){
				v10 = false;
			}
		}
		if(v00) dpcol[i][0] = min(dpcol[i-1][0], dpcol[i][0]);
		if(v10) dpcol[i][0] = min(dpcol[i-1][1], dpcol[i][0]);
		if(v01) dpcol[i][1] = min(dpcol[i-1][0] + c[i], dpcol[i][1]);
		if(v11) dpcol[i][1] = min(dpcol[i-1][1] + c[i], dpcol[i][1]);
	}

	if(dprow[n][0] >= INF && dprow[n][1] >= INF || dpcol[n][0] >= INF && dpcol[n][1] >= INF){
		cout << -1 << "\n";
	} else {
		cout << min(dprow[n][0],dprow[n][1]) + min(dpcol[n][0],dpcol[n][1]) << "\n";
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