#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define MAXN 200005

int n,m;
vector<int> adj[MAXN], radj[MAXN], verts;
bool vis[MAXN], imp = false; int component[MAXN], representative[MAXN], cIndexator = 0;

int state[MAXN], met[MAXN];

int inDeg[MAXN];
vector<int> cadj[MAXN]; set<pii> pres;

int neg(int a){
	if(a > n) return a-n;
	return a+n;
}

void dfs(int a){
	vis[a] = true;
	for(int v : adj[a]){
		if(!vis[v]){
			dfs(v);
		}
	}
	verts.push_back(a);
}

void build(int a){
	component[a] = cIndexator;
	if(!representative[cIndexator]){
		representative[cIndexator] = a;
	}
	if(component[neg(a)] == component[a]) imp = true;
	for(int v : radj[a]){
		if(!component[v]){
			build(v);
		}
	}
}

void setState(int a){
	if(met[a]) return;
	met[a] = 1;
	if(state[a] == 0){
		if(neg(a) > a){
			state[a] = 1;
			state[neg(a)] = 1;
		} else {
			state[a] = 2;
			state[neg(a)] = 2;
		}
	}
	for(int v : adj[a]){
		if(!met[v]){
			setState(v);
		}
	}
}

int main(){

	cin >> m >> n;
	for(int i = 0; i < m; i++){
		string c1,c2; int i1, i2;
		cin >> c1 >> i1 >> c2 >> i2;
		if(c1[0] == '-') i1 += n;
		if(c2[0] == '-') i2 += n;
		adj[neg(i2)].push_back(i1);
		adj[neg(i1)].push_back(i2);
		radj[i1].push_back(neg(i2));
		radj[i2].push_back(neg(i1));
	}
	for(int i = 1; i <= 2*n; i++){
		if(!vis[i]) dfs(i);
	}

	for(int i = verts.size()-1; i >= 0; i--){
		if(!component[verts[i]]){
			cIndexator++;
			build(verts[i]);
		}
	}
	if(imp){
		cout << "IMPOSSIBLE\n";
	} else {
		for(int i = 1; i <= 2*n; i++){
			for(int j = 0; j < adj[i].size(); j++){
				if(component[i] != component[adj[i][j]] && pres.end() == pres.find({component[i],component[adj[i][j]]})){
					cadj[component[i]].push_back(component[adj[i][j]]);
					pres.insert({component[i],component[adj[i][j]]});
					inDeg[component[adj[i][j]]]++;
				}
			}
		}
		queue<int> q; vector<int> vt;
		for(int i = 1; i <= cIndexator; i++){
			if(inDeg[i] == 0){
				q.push(i);
			}
		}
		while(!q.empty()){
			int nx = q.front(); q.pop();
			vt.push_back(nx);
			for(int k : cadj[nx]){
				inDeg[k]--;
				if(inDeg[k] == 0) q.push(k);
			}
		}
		for(int i = vt.size()-1; i >= 0; i--){
			setState(representative[vt[i]]);
		}
		char cnv[3] = {'0','+','-'};
		for(int i = 1; i < n; i++){
			cout << cnv[state[i]] << " ";
		}
		cout << cnv[state[n]] << "\n";
	}

	return 0;
}
