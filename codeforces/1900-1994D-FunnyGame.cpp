//https://codeforces.com/problemset/problem/1994/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define MAXN 2002
#define printvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl

int n, v[MAXN];

struct UnionFind {
	int len; vector<int> par; 
	UnionFind(int sz){
		len = sz; par = vector<int> (len+1, -1);
	}
	int find(int a){
		int rt;
		if(par[a] > 0){
			rt = find(par[a]);
			par[a] = rt;
		} else {
			rt = a;
		}
		return rt;
	}
	bool unite(int a, int b){
		int pa = find(a), pb = find(b);
		if(pa == pb) return 0;
		if((-par[pa]) > (-par[pb])){
			swap(pa,pb);
		}
		par[pb] += par[pa];
		par[pa] = pb;
		return 1;
	}
};

int main(){

	int t; cin >> t;
	for(int it = 0; it < t; it++){
		cin >> n;
		UnionFind ufind(n);
		vector<pii> opers;
		for(int i = 1; i <= n; i++){
			cin >> v[i];
		}
		for(int op = n-1; op >= 1; op--){
			vector<int> res (n , 0);
			for(int i = 1; i <= n; i++){
				//cout << res[v[i]%op] << " " << (ufind.find(res[v[i]%op]) != ufind.find(i)) << "\n";
				if(res[v[i]%op] && ufind.find(res[v[i]%op]) != ufind.find(i)){
					ufind.unite(res[v[i]%op],i);
					opers.push_back({res[v[i]%op],i});
					break;
				}
				res[v[i]%op] = i;
			}
		}
		if(ufind.par[ufind.find(1)] == (-n)){
			cout << "YES\n";
			for(int i = n-2; i >= 0; i--){
				cout << opers[i].first << " " << opers[i].second << "\n";
			}
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}