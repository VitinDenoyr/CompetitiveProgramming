//https://codeforces.com/contest/208/problem/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<vector<int>> parent (n+1, vector<int> (20, 0));
	vector<vector<int>> sons (n+1, vector<int>());
	vector<int> start_t (n+1, 0), end_t (n+1, 0), level (n+1, 0);
	vector<vector<pii>> order (n+2, vector<pii>());
	vector<int> grandpas;
	for(int i = 1; i <= n; i++){
		cin >> parent[i][0];
		if(parent[i][0] == 0){
			grandpas.push_back(i);
		} else {
			sons[parent[i][0]].push_back(i);
		}
	}

	for(int k = 1; k <= 19; k++){
		for(int i = 1; i <= n; i++){
			parent[i][k] = parent[parent[i][k-1]][k-1];
		}
	}

	int time = 1;
	vector<int> visited (n+1, 0);
	function<void(int,int)> walk = [&](int x, int lvl) {
		visited[x] = 1;
		start_t[x] = time++;
		level[x] = lvl;
		for(int u : sons[x]){
			if(visited[u]) continue;
			walk(u,lvl+1);
		}
		end_t[x] = time++;
		order[lvl].push_back({start_t[x],x});
	};

	for(int g : grandpas){
		walk(g,0);
	}

	for(int i = 0; i <= n; i++){
		sort(order[i].begin(),order[i].end());
	}

	int m; cin >> m;

	for(int _ = 1; _ <= m; _++){
		int v,p; cin >> v >> p;
		int g = v;
		for(int i = 0; i < 20; i++){
			if((p&(1<<i)) != 0){
				g = parent[g][i];
			}
		}
		if(g == 0){
			cout << 0 << " \n"[_ == m];
		} else {
			int l = 0, r = order[level[g]+p].size() - 1;
			while(l < r){
				int mid = (l+r)/2;
				if(order[level[g]+p][mid].first < start_t[g]){
					l = mid+1;
				} else {
					r = mid;
				}
			}
			int x1 = l;
			l = 0, r = order[level[g]+p].size() - 1;
			while(l < r){
				int mid = (l+r+1)/2;
				if(order[level[g]+p][mid].first > end_t[g]){
					r = mid-1;
				} else {
					l = mid;
				}
			}
			int xn = l;
			cout << xn-x1 << " \n"[_ == m];
		}
	}
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	solve();
	return 0;

}