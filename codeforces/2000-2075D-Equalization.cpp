//https://codeforces.com/contest/2075/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
const ll INF = 1000000000000000000ll;

ll dp[61][61][61] = {INF};

void solve(){

	ll x,y,x0,y0;
	cin >> x >> y;
	x0 = x; y0 = y;

	//Decompõe X e Y em dígitos
	vector<bool> dX (61, 0), dY (61, 0);
	ll mX = -1, mY = -1;
	for(ll i = 0; i <= 60; i++){
		dX[i] = x0%2;
		dY[i] = y0%2;
		if(x0%2){
			mX = i;
		}
		if(y0%2){
			mY = i;
		}
		y0 /= 2;
		x0 /= 2;
	}

	ll eq = 0;
	for(ll i = 0; i <= min(mX,mY); i++){
		if(dX[mX-i] != dY[mY-i]){
			break;
		}
		eq++;
	}

	ll qtX = mX+1, qtY = mY+1;
	ll minApg = min(qtX,qtY) - eq;

	ll resp = INF;
	for(int i = minApg; i <= 60; i++){
		for(int j = minApg; j <= 60; j++){
			if((x >> i) == (y >> j)){
				resp = min(resp, dp[60][j][i]);
			}
		}
	}
	cout << resp << "\n";
}


int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);

	for(ll i = 0; i <= 60; i++){
		for(ll j = 0; j <= 60; j++){
			for(ll k = 0; k <= 60; k++){
				dp[i][j][k] = INF;
			}
		}
	}
	dp[0][0][0] = 0;

	for(ll i = 1; i <= 60; i++){
		for(ll j = 0; j <= 60; j++){
			for(ll k = 0; k <= 60; k++){
				dp[i][j][k] = dp[i-1][j][k];
				if(j >= i) dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-i][k] + (1ll<<i));
				if(k >= i) dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k-i] + (1ll<<i));
			}
		}
	}

	ll t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}