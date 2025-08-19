//https://codeforces.com/contest/264/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define ppll pair<pll,pll>
const ll inf = 100000000000000000ll;

bool rev(pll a, pll b){
	return a.first > b.first;
}

void solve(){

	ll n,q; cin >> n >> q;
	vector<ll> v (n+1, 0), c (n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}

	for(int i = 1; i <= q; i++){
		ll a,b; cin >> a >> b;

		vector<pll> best = {{0,0},{-inf,n+1}};
		vector<ll> cmax (n+1, -inf);
		for(int i = 1; i <= n; i++){
			ll same = cmax[c[i]] + a*v[i];

			pll bestalt;
			if(best[0].second == c[i]){
				bestalt = best[1];
			} else {
				bestalt = best[0];
			}

			ll emp = b*v[i];

			ll mx = max(same,max(bestalt.first,0ll) + b*v[i]);

			if(c[i] != best[1].second && c[i] != best[0].second){
				best.push_back({mx,c[i]});
				sort(best.begin(),best.end(),rev);
				best.pop_back();
			} else if(c[i] == best[1].second){
				best[1].first = max(best[1].first,mx);
				if(best[1].first > best[0].first){
					swap(best[0],best[1]);
				}
			} else {
				best[0].first = max(best[0].first,mx);
			}
			cmax[c[i]] = max(cmax[c[i]],mx);
		}
		cout << max(best[0].first,0ll) << "\n";
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t = 1;
	while (t--){
		solve();
	}
	return 0;

}