//https://codeforces.com/problemset/problem/2060/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n, mA, mB; cin >> n >> mA >> mB;

	vector<vector<int>> adjA (n+1, vector<int>()), adjB (n+1, vector<int>()), comps (n+1, vector<int>());
	vector<pii> ares;
	vector<int> compA (n+1, 0), compB (n+1, 0); int compId = 0, c = 0;

	std::function<void(int)> findComp, flood;
	findComp = [&](int v){
		compB[v] = compId;
		comps[compId].push_back(v);
		for(int u : adjB[v]){
			if(!compB[u]) findComp(u);
		}
	};

	flood = [&](int v){
		compA[v] = c;
		for(int u : adjA[v]){
			if(!compA[u]) flood(u);
		}
	};

	for(int i = 1; i <= mA; i++){
		int u,v; cin >> u >> v;
		ares.push_back({u,v});
	}

	for(int i = 1; i <= mB; i++){
		int u,v; cin >> u >> v;
		adjB[u].push_back(v);
		adjB[v].push_back(u);
	}

	//Acha os componentes de B
	for(int i = 1; i <= n; i++){
		if(!compB[i]){
			compId++;
			findComp(i);
		}
	}

	//Primeiro passo: cada aresta (u,v) em que u e v não tao na msm componente tem q ser removida, impossivel estar certinho
	int resp = 0;
	for(int i = 1; i <= mA; i++){
		int u = ares[i-1].first, v = ares[i-1].second;
		if(compB[u] == compB[v]){
			adjA[u].push_back(v);
			adjA[v].push_back(u);
		} else {
			resp++;
		}
	}
	//Dado isso, se existem arestas (u,v), eles estão na mesma componente, mas as componentes estão incompletas
	for(int i = 1; i <= n; i++){
		if(!compA[i]){
			c++;
			flood(i);
		
			for(int j : comps[compB[i]]){
				if(!compA[j]){
					c++;
					flood(j);
					resp++;
				}
			}
		}
	}

	cout << resp << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}