//https://codeforces.com/contest/2078/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define pci pair<char,ll>

void solve(){

	ll n; cin >> n;
	vector<pci> l (n+1, {0,0}), r(n+1, {0,0});
	vector<ll> dpl (n+2, 1), dpr (n+2, 1);
	for(ll i = 1; i <= n; i++){
		cin >> l[i].first >> l[i].second;
		cin >> r[i].first >> r[i].second;
	}

	//dpl[i] = entrando no portão esquerdo com K, + quantos múltiplos de K eu posso ficar no máximo?
	dpl[n+1] = 1; dpr[n+1] = 1;
	for(ll i = n; i >= 1; i--){
		if(l[i].first == 'x'){
			dpl[i] = dpl[i+1] + (l[i].second-1)*max(dpl[i+1],dpr[i+1]);
		} else {
			dpl[i] = dpl[i+1];
		}
		if(r[i].first == 'x'){
			dpr[i] = dpr[i+1] + (r[i].second-1)*max(dpl[i+1],dpr[i+1]);
		} else {
			dpr[i] = dpr[i+1];
		}
	}

	ll resp = dpl[1] + dpr[1];
	//cout << resp << "\n";
	for(int i = 1; i <= n; i++){
		if(l[i].first == '+'){
			resp += l[i].second*max(dpl[i+1],dpr[i+1]);
		}
		if(r[i].first == '+'){
			resp += r[i].second*max(dpl[i+1],dpr[i+1]);
		}
	}
	cout << resp << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}