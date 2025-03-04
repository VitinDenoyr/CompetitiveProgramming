//https://codeforces.com/problemset/problem/2064/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const ll mod = 998244353;

struct UnionFind {
	int len;
	vector<int> parent;
	vector<int> value;
	vector<int> color;
	vector<int> prv, nxt;
	UnionFind(int _n){
		len = _n;
		parent = vector<int>(_n+1, -1);
		value = vector<int>(_n+1, -1);
		color = vector<int>(_n+1, -1);
		prv = vector<int>(_n+1, -1);
		nxt = vector<int>(_n+1, -1);
	}
	int find(int a){
		if(parent[a] > 0){
			parent[a] = find(parent[a]);
			return parent[a];
		}
		return a;
	}
	void unite(int a, int b){
		int pa = find(a), pb = find(b);
		if(-parent[pa] < -parent[pb]) swap(pa,pb);
		parent[pb] = pa;
		nxt[pa] = max(nxt[pa],nxt[pb]);
		prv[pa] = min(prv[pa],prv[pb]);
		value[pa] += value[pb];
	}
};

bool comp(pii a, pii b){
	return a.first < b.first;
}

void solve(){

	int n; cin >> n;
	vector<int> p (n+1, 0),c (n+1, 0);
	vector<pii> pairs;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		pairs.push_back({p[i],i});
	}
	sort(pairs.begin(),pairs.end(),comp);
	
	UnionFind ufind(n);
	for(int i = 1; i <= n; i++){
		ufind.color[i] = c[i]; ufind.value[i] = 1;
		ufind.prv[i] = i-1; ufind.nxt[i] = i+1;
		if(i > 1 && ufind.color[i] == ufind.color[i-1]){
			ufind.unite(i,i-1);
		}
	}

	ll acc = 1;
	for(int i = 0; i <= n-2; i++){
		int j = ufind.find(pairs[i].second);
		acc = (acc * ((ll)ufind.value[j]))%mod;
		ufind.value[j]--;

		if(ufind.value[j] == 0){
			int qti = 0;
			if(ufind.prv[j] >= 1){
				ufind.nxt[ufind.find(ufind.prv[j])] = ufind.nxt[j];
				qti++;
			}
			if(ufind.nxt[j] <= n){
				ufind.prv[ufind.find(ufind.nxt[j])] = ufind.prv[j];
				qti++;
			}
			if(qti == 2 && ufind.color[ufind.prv[j]] == ufind.color[ufind.nxt[j]]){
				ufind.unite(ufind.prv[j],ufind.nxt[j]);
			}
		}
	}
	cout << acc << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}