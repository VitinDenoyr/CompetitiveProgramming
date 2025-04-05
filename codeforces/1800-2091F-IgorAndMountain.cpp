//https://codeforces.com/problemset/problem/2091/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
const ll mod = 998244353;
#define R(a,i,j) if(0) cout << "R(" << a << "," << i << "," << j << ") = " << routes[a][i][j] << "\n"

void solve(){

	ll n,m,d; cin >> n >> m >> d;
	vector<vector<ll>> routes[2];
	vector<vector<ll>> a (n+1, vector<ll>(m+1, 0));
	routes[0] = vector<vector<ll>> (n+1, vector<ll> (m+1, 0));
	routes[1] = vector<vector<ll>> (n+1, vector<ll> (m+1, 0));
	vector<vector<ll>> sum (n+1, vector<ll> (m+1, 0));

	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			char c; cin >> c;
			if(c == 'X'){
				a[i][j] = 1;
			}
		}
	}

	//Uma rota na última linha é possível bastando ter um hold
	for(ll j = 1; j <= m; j++){
		routes[1][n][j] = (ll)a[n][j];
		R(1,n,j);
	}

	for(ll i = n; i >= 1; i--){
		//Atualiza rotas que sobram 1 na linha i
		if(i != n){
			for(ll j = 1; j <= m; j++){
				routes[1][i][j] = (a[i][j] == 1)*((sum[i+1][min(j+d-1,m)] - sum[i+1][max(j-d,0ll)])%mod + mod)%mod;
				R(1,i,j);
			}
		}

		//Coloca as rotas que sobram 1 na sum
		for(ll j = 1; j <= m; j++){
			sum[i][j] = (sum[i][j-1] + routes[1][i][j])%mod;
		}

		//Atualiza rotas que sobram 0 na linha i
		for(ll j = 1; j <= m; j++){
			routes[0][i][j] = (a[i][j] == 1)*((sum[i][min(j+d,m)] - sum[i][max(j-d-1,0ll)] - routes[1][i][j])%mod + mod)%mod;
			R(0,i,j);
		}

		//Coloca as rotas que sobram 0 na sum
		for(ll j = 1; j <= m; j++){
			sum[i][j] = (sum[i][j-1] + routes[1][i][j] + routes[0][i][j])%mod;
		}
	}

	ll resp = 0;
	for(ll j = 1; j <= m; j++){
		resp = (resp + routes[0][1][j] + routes[1][1][j])%mod;
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