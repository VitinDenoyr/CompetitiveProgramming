#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define printvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl

int n, qtGrads = 0;
int nxt[MAXN][1], posGrad[MAXN], distCyc[MAXN], arriveIn[MAXN], gradNum[MAXN], cycSize[MAXN];
vector<int> ant[MAXN];
bool inCyc[MAXN]; int vis[MAXN];

int conv(int k, int t){
	while(k < 0){
		k += t;
	}
	return k;
}

void backtrackBfs(int a, int n0){
	queue<int> q;
	for(int v : ant[a]){
		q.push(v);
	}
	vis[a] = 2;
	while(!q.empty()){
		int c = q.front(); q.pop();
		distCyc[c] = distCyc[nxt[c][0]] + 1;
		arriveIn[c] = arriveIn[nxt[c][0]];
		gradNum[c] = n0; vis[c] = 2;
		for(int v : ant[c]){
			if(vis[v] != 2){
				q.push(v);
			}
		}
	}
}

void process(int a){
	qtGrads++;

	vis[a] = 1; gradNum[a] = qtGrads;
	while(!vis[nxt[a][0]]){
		a = nxt[a][0];
		vis[a] = 1;
		gradNum[a] = qtGrads;
	}

	a = nxt[a][0];
	inCyc[a] = true; distCyc[a] = 0; posGrad[a] = 1; arriveIn[a] = a;
	while(!inCyc[nxt[a][0]]){
		posGrad[nxt[a][0]] = posGrad[a] + 1;
		a = nxt[a][0];
		inCyc[a] = true;
		distCyc[a] = 0;
		arriveIn[a] = a;
	}
	cycSize[gradNum[a]] = posGrad[a];

	int nd = a;
	for(int p = 1; p <= posGrad[a]; p++){
		nd = nxt[nd][0]; vis[nd] = 2;
		for(int v : ant[nd]){
			if(!inCyc[v]){
				distCyc[v] = 1; arriveIn[v] = nd; gradNum[v] = qtGrads;
				backtrackBfs(v, qtGrads);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> nxt[i][0];
		ant[nxt[i][0]].push_back(i);
	}
	for(int i = 1; i <= n; i++){
		if(vis[i] == 0){
			process(i);
		}
	}

	for(int i = 1; i < n; i++){
		cout << (distCyc[i] + cycSize[gradNum[i]]) << " ";
	}
	cout << (distCyc[n] + cycSize[gradNum[n]]) << "\n";

	return 0;
}