#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define prllvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl
#define MAXN 100005

int n,m;

struct UnionFind { //Union by rank -> upper bound for tree height, Union by size -> qtd. of elements
	vector<int> parent;
	vector<int> sizec;
	/*vector<int> rank;*/
	UnionFind(int n){
		parent = vector<int> (n+1, -1);
		sizec = vector<int> (n+1, 1);
		/*rank = vector<int> (n+1, 0);*/
	}
	int find(int a){
		int rt = a, nd0 = a;
		while(parent[rt] != -1){
			rt = parent[rt];
		}
		while(parent[nd0] != -1){
			int nd1 = nd0;
			nd0 = parent[nd0];
			parent[nd1] = rt;
		}
		return rt;
	}
	int unite(int a, int b){
		int pa = find(a), pb = find(b);
		if(pa == pb) return 0;
		if(sizec[pa] < sizec[pb]){
			swap(pa,pb);
		}
		parent[pb] = pa;
		sizec[pa] += sizec[pb];
		return sizec[pa];
	}
	/*bool unite(int a, int b){
		int pa = find(a), pb = find(b);
		if(pa == pb) return 0;
		if(rank[pa] < rank[pb]){
			swap(a,b); swap(pa,pb);
		}
		parent[pb] = pa;
		rank[pa] += (rank[pa] == rank[pb]);
		return true;
	}*/
};

int main(){

	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	UnionFind u(n); int maxSize = 1, qtComps = n;
	for(int i = 0; i < m; i++){
		int x,y;
		cin >> x >> y;
		int ans = u.unite(x,y);
		if(ans > 0) qtComps--;
		maxSize = max(maxSize, ans);
		cout << qtComps << " " << maxSize << "\n";
	}

	return 0;
}