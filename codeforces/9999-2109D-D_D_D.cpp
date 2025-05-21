#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n,m,l; cin >> n >> m >> l;
	vector<vector<int>> adj (n+1, vector<int>());
	vector<vector<int>> dist (n+1, vector<int>(2, -1));
	ll sumy = 0, mI = 99999999999ll, mP = 99999999998ll;
	for(int i = 1; i <= l; i++){
		ll _; cin >> _;
		if(_%2) mI = min(mI,_);
		if((_+1)%2) mP = min(mP,_);
		sumy += _;
	}
	for(int i = 1; i <= m; i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<vector<int>> q;
	q.push({1,0,0}); dist[1][0] = 0;
	while(!q.empty()){
		int x = q.front()[0], c = q.front()[1], d = q.front()[2]; q.pop();
		for(int u : adj[x]){
			if(dist[u][1-c] == -1){
				dist[u][1-c] = d+1;
				q.push({u,1-c,d+1});
			}
		}
	}


	string ans = "";
	for(int i = 1; i <= n; i++){
		if((sumy >= dist[i][sumy%2] && dist[i][sumy%2] != -1) || (sumy-mI >= dist[i][(sumy-mI)%2] && dist[i][(sumy-mI)%2] != -1)){
			ans += "1";
		} else {
			ans += "0";
		}
	}
	cout << ans << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}