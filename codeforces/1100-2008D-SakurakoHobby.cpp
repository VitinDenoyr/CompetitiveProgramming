//https://codeforces.com/problemset/problem/2008/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct UnionFind {
	int len; vector<int> parent, blacks;
	UnionFind(int _n, const vector<int>& _b) : len(_n){
		parent = vector<int>(len+1,-1);
		blacks = _b;
	}
	int find(int ind){
		if(parent[ind] < 0) return ind;
		parent[ind] = find(parent[ind]);
		return parent[ind];
	}
	void unite(int a, int b){
		int pA = find(a), pB = find(b);
		if(pA == pB) return;
		if(parent[pA] < parent[pB]) swap(pA,pB);
		parent[pB] += parent[pA];
		blacks[pB] += blacks[pA];
		parent[pA] = pB;
	}
};

int main(){

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v (n+1), resp(n+1,0); vector<int> black (n+1,0);
		for(int i = 1; i <= n; i++){
			cin >> v[i];
		}
		string s; cin >> s;
		for(int i = 0; i < n; i++){
			if(s[i] == '0') black[i+1] = 1;
		}

		UnionFind ufind(n,black);
		vector<int> vis(n+1,0);

		for(int i = 1; i <= n; i++){
			if(v[i] == i){
				resp[i] = black[i];
				vis[i] = 2*i;
				continue;
			};
			if(ufind.parent[ufind.find(i)] < -1){
				resp[i] = ufind.blacks[ufind.find(i)];
				continue;
			}

			bool virgem = (vis[i] == 0 || vis[i]%2 == 1);
			vis[i] = 2*i-1;
			int next = v[i];
			
			while(vis[next] < 2*i-1){
				if(vis[next] != 0 && vis[next]%2 == 0){ //faz parte de um laço
					resp[i] += ufind.blacks[ufind.find(next)];
					break;
				} else {
					vis[next] = 2*i-1;
					resp[i] += black[next];
					next = v[next];
				}
			}
			if(next == i && virgem && black[i]) resp[i]++;

			if(vis[next]%2 == 1){
				int root = next; next = v[next];
				while(next != root){
					ufind.unite(root, next);
					next = v[next];
				}
			}
		}

		for(int i = 1; i <= n; i++){
			cout << resp[i] << " \n"[i==n];
		}
	}	

	return 0;
}