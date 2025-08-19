#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const ll mod = 1000000007;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

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

void solve(){

	ll n,m,k; cin >> n >> m >> k;
	map<pii,int> cor;
	map<pii,int> viz;
	int rem = 0;
	int qtQuina = 0, qtBorda = 0, qtMeio = 0;
	for(int i = 1; i <= k; i++){
		ll l,c,color; cin >> l >> c >> color;
		cor[{l,c}] = color;
		int tp = 4 - ((l-1)%(n-1) == 0) - ((c-1)%(m-1) == 0);
		viz[{l,c}] = tp;
		rem = (rem + ((((l-1)%(n-1) == 0) + ((c-1)%(m-1) == 0))%2)*(color == 1))%2;

		if(tp == 4){
			qtMeio++;
		} else if(tp == 3){
			qtBorda++;
		} else {
			qtQuina++;
		}
	}

	ll resp = 1; ll lastMoveIsForced = 1;

	ll qtB = (2ll*n + 2ll*m - qtBorda - 8ll);
	if(rem == 1 && qtB == 0){
		cout << 0 << "\n";
		return;
	}
	if(qtB != 0) qtB -= lastMoveIsForced;

	ll qtQ = (4 - qtQuina);

	ll qtM = (((n-2ll)*(m-2ll))%(mod-1) - qtMeio + 2ll*(mod-1))%(mod-1);

	ll expo = ((qtB + qtQ + qtM)%(mod-1) + (mod-1))%(mod-1);

	cout << fexpo(2ll,expo) << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}