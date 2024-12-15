#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define prllvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl
#define MAXN 100005

int n,m;

struct UnionFind {
	vector<int> v;
	UnionFind(int n){
		v = vector<int> (n+1, -1);
	}

	int find(int a){
		if(v[a] < 0) return a;
		v[a] = find(v[a]);
		return v[a];
	}

	int unite(int a, int b){ //Retorna se a união foi necessária
		int pa = find(a), pb = find(b);
		if(pa == pb) return 0;
		if(-v[pa] < -v[pb]){
			swap(pa,pb);
		}
		v[pa] += v[pb];
		v[pb] = pa;
		return -v[pa];
	}
};

int main(){

	cin >> n >> m;
	UnionFind u(n);
	int qtComponents = n, mx = 1;
	for(int i = 0; i < m; i++){
		int x,y; cin >> x >> y;
		int res = u.unite(x,y);
		qtComponents -= (res > 0);
		mx = max(mx, res);
		cout << qtComponents << " " << mx << "\n";
	}

	return 0;
}