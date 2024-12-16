#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005

int n,m;
vector<int> order, prv;
vector<vector<int>> adj;

int main(){

	cin >> n >> m;
	prv = vector<int> (n+1, 0);
	adj = vector<vector<int>> (n+1, vector<int>());

	for(int i = 0; i < m; i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		prv[b]++;
	}

	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(prv[i] == 0) q.push(i);
	}

	while(!q.empty()){
		int nxt = q.front(); q.pop();
		order.push_back(nxt);
		for(int k : adj[nxt]){
			if((--prv[k]) == 0) q.push(k);
		}
	}

	if(order.size() == n){
		for(int e = 0; e < n; e++){
			cout << order[e] << " \n"[e == n-1];
		}
	} else {
		cout << "IMPOSSIBLE\n";
	}

	return 0;
}