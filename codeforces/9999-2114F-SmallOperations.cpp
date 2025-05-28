//https://codeforces.com/contest/2114/problem/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int mdc(int x, int y){
	if(x == 0) return y;
	return mdc(y%x, x);
}

vector<vector<int>> divs (1000001, vector<int>());
vector<pii> dp (1000001, {0,0}); int timee = 0;

void solve(){

	timee++;
	int x,y,mx; cin >> x >> y >> mx;
	int md = mdc(x,y);
	x /= md;
	y /= md;

	function<int(int)> calc = [&](int k) -> int {
		if(k == 1) return 0;
		if(k <= mx) return 1;
		
		if(dp[k].first == timee){
			return dp[k].second;
		} else {
			dp[k].second = 1000000000;
		}

		for(int dv : divs[k]){
			if(dv > mx) break;
			dp[k].second = min(calc(k/dv) + 1, dp[k].second);
		}
		dp[k].first = timee;
		return dp[k].second;
	};

	int resp = calc(x) + calc(y);
	if(resp >= 1000000000){
		cout << -1 << "\n";
	} else {
		cout << resp << "\n";
	}
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);

	for(int i = 2; i <= 1000000; i++){
		for(int j = i; j <= 1000000; j += i){
			divs[j].push_back(i);
		}
	}

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}