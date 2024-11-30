//https://codeforces.com/contest/1949/problem/I
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define prllvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl
#define MAXN 1001

vector<ll> color (MAXN,0);
vector<ll> x (MAXN), y (MAXN), r (MAXN);
vector<vector<ll>> adj (MAXN, vector<ll>());

ll cor1 = 0, cor2 = 0; bool st = true;
bool dfs(ll i, ll cor){
	color[i] = cor;
	if(cor == 1){
		cor1++;
	} else {
		cor2++;
	}
	for(ll v : adj[i]){
		if(color[v] == color[i]){
			st = false;
		} else if(!color[v]){
			dfs(v,3-cor);
		}
	}
	return st;
}

int main(){

	ll n; cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> x[i] >> y[i] >> r[i];
		for(ll j = 0; j < i; j++){
			//OBS: Esse if de baixo é uma porcaria e ctz que vai passar do limite de long long em algum caso mas blz
			if((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) == (r[i]+r[j])*(r[i]+r[j])){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	bool ans = false;
	for(int i = 0; i < n; i++){
		if(!color[i]){
			cor1 = 0; cor2 = 0; st = true;
			bool suc = dfs(i,1);
			if(suc && (cor1 != cor2)){
				ans = true;
				break;	
			}
		}
	}
	if(ans){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}