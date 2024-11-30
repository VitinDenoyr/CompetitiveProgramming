//https://codeforces.com/contest/2014/problem/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>

int n,c;
vector<ll> v;
vector<int> prv, vis;
vector<vector<int>> adj;
vector<vector<ll>> dp;

pll dfs(int x){
	//cout << "!" << x << "\n";
	vis[x] = 1;

	ll tb[2][2] = {{0,0},{0,0}}; //linha 0: não escolhi o cara de agora. linha 1: escolhi o cara de agora
	//coluna 0: não escolhi o pai dele. coluna 1: escolhi o pai dele
	if(prv[x] > 0){
		tb[0][0] = dp[prv[x]][0];
		tb[0][1] = dp[prv[x]][1];
		tb[1][0] = dp[prv[x]][0] + v[x];
		tb[1][1] = dp[prv[x]][1] + v[x] - 2*c;

		dp[x][0] = max(tb[0][0],tb[0][1]);
		dp[x][1] = max(tb[1][0],tb[1][1]);
	} else {
		tb[0][0] = tb[0][1] = 0;
		tb[1][0] = tb[1][1] = v[x];

		dp[x][0] = 0;
		dp[x][1] = v[x];
	}

	//cout << "dp[" << x << "] = " << dp[x][0] << " , " << dp[x][1] << "\n"; 
	for(int vz : adj[x]){
		if(vis[vz]) continue;
		prv[vz] = x;
		pll resp = dfs(vz);
		ll l0_add = resp.first - dp[x][0]; //sem escolher esse cara, aumenta nisso com esse branch da arvore.
		ll l1_add = resp.second - dp[x][1]; //escolhendo o cara, aumenta nisso com esse branch da arvore.

		tb[0][0] += l0_add; tb[0][1] += l0_add;
		tb[1][0] += l1_add; tb[1][1] += l1_add;
		dp[x][0] = max(tb[0][0],tb[0][1]);
		dp[x][1] = max(tb[1][0],tb[1][1]);
	}
	return {max(tb[0][0],tb[1][0]),max(tb[0][1],tb[1][1])};
}

int main(){

	int t; cin >> t;
	while(t--){
		cin >> n >> c;
		v = vector<ll> (n+1, 0); prv = vector<int> (n+1, 0);
		vis = vector<int> (n+1, 0);
		dp = vector<vector<ll>> (n+1, vector<ll>(2,0));
		adj = vector<vector<int>> (n+1, vector<int>());

		for(int i = 1; i <= n; i++){
			cin >> v[i];
		}
		for(int i = 1; i < n; i++){
			int u,v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		pll r = dfs(1);
		cout << max(r.first,r.second) << "\n";
	}

	return 0;
}