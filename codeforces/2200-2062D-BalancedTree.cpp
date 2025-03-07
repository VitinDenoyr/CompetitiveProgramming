//https://codeforces.com/problemset/problem/2062/D
#define Solucao1 "Subárvores por vértices"
/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

bool comp(ll a, ll b){
	return a > b;
}

void solve(){

	ll n; cin >> n;
	vector<ll> le (n+1, 0), ri (n+1, 0);
	vector<vector<ll>> adj (n+1, vector<ll>());

	for(ll i = 1; i <= n; i++){
		cin >> le[i] >> ri[i];
	}

	for(ll i = 1; i <= n-1; i++){
		ll u,v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<ll> vis (n+1, 0);
	vector<ll> adder (n+1, 0);
	function<pii(ll)> flood = [&](ll x) -> pii {
		//cout << "flood(" << x << ")\n";
		vis[x] = 1;
		ll mxReceptor = 0; int qtsons = 0;
		vector<ll> vals;
		for(ll u : adj[x]){
			if(!vis[u]){
				qtsons++;
				pii resp = flood(u);
				vals.push_back(resp.first - resp.second);
				mxReceptor = max(mxReceptor, resp.first - resp.second);
				adder[x] += resp.second;
			}
		}
		if(qtsons == 0){
			return {le[x],0};
		}
		//cout << "now, to fix all sons of " << x << " I need " << mx <<  " with adder of " << adder[x] << "\n";
		if(mxReceptor + adder[x] < le[x] + adder[x]){
			//cout << "I'm bigger than that, so I need the sons to reach " << le[x] + adder[x] << " while maintaining the adder of " << adder[x] << "\n";
			return {le[x] + adder[x], adder[x]};
		} else if(mxReceptor + adder[x] > ri[x] + adder[x]){
			ll target = mxReceptor + adder[x];
			ll maxnatural = ri[x] + adder[x];
			ll diff = target - maxnatural;
			sort(vals.begin(),vals.end(),comp);
			//cout << "I'm small, so I need my sons to diminish relatively " << diff << " times to match\n";
			for(ll j = 0; j < vals.size()-1; j++){
				if(diff <= (vals[j] - vals[j+1])){
					return {target + diff*j, adder[x] + diff*(j+1)};
				} else {
					//cout << "I need more than " << vals[j] - vals[j+1] << " operations\n";
					diff -= (vals[j] - vals[j+1]);
					adder[x] += (vals[j] - vals[j+1])*(j+1);
					target += (vals[j] - vals[j+1])*j;
				}
			}
			return {target + diff*(vals.size()-1), adder[x] + diff*(vals.size())};
		} else {
			//cout << "I can work with " << mxReceptor + adder[x] << " and an adder of " << adder[x] << "\n";
			return {mxReceptor + adder[x], adder[x]};
		}
	};
	pii respy = flood(1);
	cout << respy.first << "\n";
}s

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}
*/

#define Solucao2 "Subárvores por arestas"

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

void solve(){
	ll n; cin >> n;
	vector<ll> le (n+1, 0), ri (n+1, 0);
	vector<vector<ll>> adj (n+1, vector<ll>());

	for(ll i = 1; i <= n; i++){
		cin >> le[i] >> ri[i];
	}

	for(ll i = 1; i <= n-1; i++){
		ll u,v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<ll> vis (n+1, 0);
	vector<ll> value (n+1, 0);

	//Escolhe os valores iniciais
	function<ll(ll)> flood = [&](ll x) -> ll {
		vis[x] = 1;
		ll maxi = -1;
		for(ll u : adj[x]){
			if(!vis[u]){
				maxi = max(maxi, flood(u));
			}
		}
		value[x] = min(max(le[x],maxi),ri[x]);
		return value[x];
	};
	flood(1);

	//Calcula o máximo total
	vis = vector<ll>(n+1, 0);
	ll rootval = value[1];
	function<void(ll)> propagate = [&](ll x) {
		vis[x] = 1;
		for(ll u : adj[x]){
			if(!vis[u]){
				propagate(u);
				if(value[u] > value[x]){
					rootval += (value[u] - value[x]);
				}
			}
		}
	};
	propagate(1);
	cout << rootval << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}