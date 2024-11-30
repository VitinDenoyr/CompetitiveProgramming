#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define MAXN 1002

int n,m;
pii comeco, fim;
char g[MAXN][MAXN];
bool vis[MAXN][MAXN];

int prv[MAXN][MAXN];

int av[4] = {-1,0,1,0}, bv[4] = {0,1,0,-1};
string dir = "URDL";

queue<pii> q;

void bfs(int a, int b){
	q.push({a,b});
	vis[a][b] = 1;
	while(!q.empty()){
		pii next = q.front(); q.pop();
		a = next.first, b = next.second;
		for(int i = 0; i < 4; i++){
			int a0 = a + av[i], b0 = b + bv[i];

			if(a0 < 0 || b0 < 0 || a0 >= n || b0 >= m) continue;
			if(g[a0][b0] == '#') continue;
			if(vis[a0][b0]) continue;

			vis[a0][b0] = 1;
			prv[a0][b0] = i;
			q.push({a0,b0});
		}
	}
}

void construct(int a, int b){
	vector<int> corr;
	while((pii){a,b} != comeco){
		int pr = prv[a][b];
		corr.push_back(pr);
		a -= av[pr]; b -= bv[pr];
	}
	reverse(corr.begin(),corr.end());
	cout << corr.size() << "\n";
	for(int j : corr) cout << dir[j];
	cout << "\n";
}
 
int main(){
 
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> g[i][j];
			if(g[i][j] == 'A'){
				comeco = {i,j};
			} else if(g[i][j] == 'B'){
				fim = {i,j};
			}
		}
	}
	bfs(comeco.first,comeco.second);
	if(vis[fim.first][fim.second]){
		cout << "YES\n";
		construct(fim.first,fim.second);
	} else {
		cout << "NO\n";
	}
 
	return 0;
}