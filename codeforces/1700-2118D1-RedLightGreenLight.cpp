//https://codeforces.com/problemset/problem/2118/D1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
 
ll mod (ll x, ll y){
	return (x%y+y)%y;
}
 
void solve(){
 
	ll n,k; cin >> n >> k;
	vector<ll> a (n+1, 0), d (n+1, 0);
	map<ll,set<ll>> ri, le;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> d[i];
		ri[mod(a[i]-d[i],k)].insert(a[i]);
		le[mod(a[i]+d[i],k)].insert(a[i]);
	}
 
	//Montagem do grafo
	map<ll,ll> adj;
	for(ll i = 1; i <= n; i++){
		ll pD = mod(a[i] - d[i],k);
		auto nxD = ri[pD].upper_bound(a[i]);
		if(nxD != ri[pD].end()){
			adj[2*a[i]+1] = 2*(*nxD)+0;
		}
 
		ll pE = mod(a[i] + d[i],k);
		auto nxE = le[pE].lower_bound(a[i]);
		if(nxE != le[pE].begin()){
			nxE--;
			adj[2*a[i]+0] = 2*(*nxE)+1;
		}
	}
 
	//Encontra os ciclos
	map<ll,ll> inCycle, vis;
	function<void(ll)> dfs = [&](ll x){
		vis[x] = 1;
		if(adj[x] > 0){
			if(vis[adj[x]] == 1){
				inCycle[adj[x]] = 1;
			} else {
				dfs(adj[x]);
			}
		}
		vis[x] = 2;
	};
	for(int i = 1; i <= n; i++){
		if(!vis[2*a[i]]) dfs(2*a[i]);
		if(!vis[2*a[i]+1]) dfs(2*a[i]+1);
	}
 
	//Completa os ciclos
	for(auto ii : inCycle){
		ll i = ii.first;
		if(inCycle[i] == 1){
			ll j = i;
			while(inCycle[j] != 2){
				inCycle[j] = 2;
				j = adj[j];
			}
		}
	}
 
	//Responde as queries
	ll q; cin >> q;
	for(int i = 1; i <= q; i++){
		ll qi; cin >> qi;
		ll padr = qi%k;
 
		auto nx = ri[padr].lower_bound(qi);
		if(nx != ri[padr].end() && inCycle[2*(*nx)]){
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
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