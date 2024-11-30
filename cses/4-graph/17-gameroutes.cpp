#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MOD 1000000007
 
ll n,m;
vector<ll> adj[MAXN];
bool met[MAXN]; ll qt[MAXN];
 
void dfs(ll a){
	int r = 0;
	for(ll v : adj[a]){
		if(met[v]){
			r += qt[v];
			r %= MOD;
		} else {
			dfs(v); //1 4 
			r += qt[v];
			r %= MOD;
		}
	}
	qt[a] = r;
	met[a] = true;
}
 
int main(){
 
	cin >> n >> m;
	for(ll i = 0; i < m; i++){
		ll a,b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	qt[n] = 1; met[n] = 1;
	dfs(1);
	cout << qt[1] << "\n";
 
	return 0;
}