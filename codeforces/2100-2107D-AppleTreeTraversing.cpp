//https://codeforces.com/contest/2107/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

bool comp(vector<int> y, vector<int> z){
	if(y[0] > z[0]) return true;
	if(y[0] < z[0]) return false;
	if(y[1] > z[1]) return true;
	if(y[1] < z[1]) return false;
	return y[2] > z[2];
}

void solve(){

	int n; cin >> n;
	vector<vector<int>> adj (n+1, vector<int>());
	vector<int> exist (n+1, 1), prevv (n+1, 0); int ex = n;
	queue<int> q;
	for(int i = 1; i < n; i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		q.push(i);
	}
	q.push(n);

	vector<int> visit (n+1, 0); int visId = 0;

	function<vector<int>()> doIt = [&]() -> vector<int> {
		while(!exist[q.front()]){
			q.pop();
		}

		int at = q.front(); visId++;

		queue<pii> que;
		que.push({at,0});
		vector<pii> largests;
		while(!que.empty()){
			at = que.front().first;
			int ds = que.front().second;
			que.pop();
			for(int u : adj[at]){
				if(!exist[u]) continue;
				if(visit[u] == visId) continue;
				que.push({u,ds+1});
			}
			visit[at] = visId;
			if(!largests.empty() && ds > largests[0].second){
				largests.clear();
				largests.push_back({at,ds});
			} else if(largests.empty() || ds == largests[0].second){
				largests.push_back({at,ds});
			}
		}

		int mini = largests[0].first;
		for(pii z : largests){
			if(z.first > mini){
				mini = z.first;
			}
		}

		visId++;
		largests.clear();
		que.push({mini,0});
		while(!que.empty()){
			at = que.front().first;
			int ds = que.front().second;
			que.pop();
			for(int u : adj[at]){
				if(!exist[u]) continue;
				if(visit[u] == visId) continue;
				prevv[u] = at;
				que.push({u,ds+1});
			}
			visit[at] = visId;
			if(!largests.empty() && ds > largests[0].second){
				largests.clear();
				largests.push_back({at,ds});
			} else if(largests.empty() || ds == largests[0].second){
				largests.push_back({at,ds});
			}
		}

		int maxi = largests[0].first;
		for(pii z : largests){
			if(z.first > maxi){
				maxi = z.first;
			}
		}

		ex -= largests[0].second+1;
		int maxic = maxi;
		while(maxic != mini){
			exist[maxic] = 0;
			maxic = prevv[maxic];
		}
		exist[mini] = 0;
		return {largests[0].second+1, max(mini, maxi), min(mini, maxi)};
	};

	vector<int> ans; vector<vector<int>> answ;
	while(ex > 0){
		answ.push_back({doIt()});
	}

	sort(answ.begin(), answ.end(),comp);

	for(int i = 1; i <= answ.size(); i++){
		cout << answ[i-1][0] << " " << answ[i-1][1] << " " << answ[i-1][2] << " \n"[i==answ.size()];
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