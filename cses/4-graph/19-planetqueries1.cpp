#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define prllvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl

ll n, q, nxt[MAXN][31];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> q;
	for(ll i = 1; i <= n; i++){
		cin >> nxt[i][0];
	}
	for(ll r = 1; r <= 30; r++){
		for(ll i = 1; i <= n; i++){
			nxt[i][r] = nxt[nxt[i][r-1]][r-1];
		}
	}
	for(ll i = 0; i < q; i++){
		ll x,k; cin >> x >> k;
		for(ll b = 30; b >= 0; b--){
			if((k&(ll)((ll)1<<b)) != 0){
				x = nxt[x][b];
				k -= (1<<b);
			}
		}
		cout << x << "\n";
	}

	return 0;
}