#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1002
#define INF 10000007
#define pii pair<int,int>
 
int n, m, qtM = 0; pii start;
char tile[MAXN][MAXN];
int vis[MAXN][MAXN], visInd = 1;
pii prv[MAXN][MAXN];
vector<pii> borderList, monsterList;
vector<int> distBorder;
int dist[MAXN][MAXN], mdist[MAXN][MAXN];
 
int av[4] = {1,0,-1,0}, bv[4] = {0,-1,0,1};
string conv = "DLUR";
 
bool isBorder(int a, int b){
	return (a == 1 || b == 1 || a == n || b == m);
}
 
bool invalid(int a, int b){
	return (a > n || b > m || a < 1 || b < 1);
}
 
void bfs(int a, int b){
	queue<pii> q;
	q.push({a,b});
	vis[a][b] = true;
	while(!q.empty()){
		pii p = q.front(); q.pop();
		a = p.first, b = p.second;
		for(int i = 0; i < 4; i++){
			int a0 = a + av[i], b0 = b + bv[i];
			if(!invalid(a0,b0) && tile[a0][b0] == '.' && !vis[a0][b0]){
				vis[a0][b0] = 1;
				dist[a0][b0] = dist[a][b] + 1;
				prv[a0][b0] = {a,b};
				q.push({a0,b0});
				if(isBorder(a0,b0)){
					borderList.push_back({a0,b0});
					distBorder.push_back(dist[a0][b0]);
				}
			}
		}
	}
}
 
pii checkForMonsters(){
	for(int k = 0; k < borderList.size(); k++){
		visInd++;
 		bool continueK = false;
		pii pr = borderList[k];
		queue<pii> q; q.push(pr);
		vis[pr.first][pr.second] = visInd;
		dist[pr.first][pr.second] = 0;
		while(!q.empty()){
			pii p = q.front(); q.pop();
			int a = p.first, b = p.second;
			for(int i = 0; i < 4; i++){
				int a0 = a + av[i], b0 = b + bv[i];
				if(!invalid(a0,b0) && tile[a0][b0] != '#' && vis[a0][b0] < visInd && dist[a][b] < distBorder[k]){
					vis[a0][b0] = visInd;
					dist[a0][b0] = dist[a][b] + 1;
					q.push({a0,b0});
					if(tile[a0][b0] == 'M'){
						continueK = true;
						break;
					}
				}
			}
			if(continueK) break;
		}
		if(continueK == false) return pr;
	}
	return {-1,-1};
}

pii checkForEndings(){
	for(int k = 0; k < monsterList.size(); k++){
		visInd++;
		pii pr = monsterList[k];
		queue<pii> q; q.push(pr);
		vis[pr.first][pr.second] = visInd;
		mdist[pr.first][pr.second] = 0;
		while(!q.empty()){
			pii p = q.front(); q.pop();
			int a = p.first, b = p.second;
			for(int i = 0; i < 4; i++){
				int a0 = a + av[i], b0 = b + bv[i];
				if(!invalid(a0,b0) && tile[a0][b0] != '#' && vis[a0][b0] < visInd){
					vis[a0][b0] = visInd;
					mdist[a0][b0] = mdist[a][b] + 1;
					q.push({a0,b0});
					if(isBorder(a0,b0) && dist[a0][b0] >= mdist[a0][b0]){
						dist[a0][b0] = INF;
						tile[a0][b0] = '#';
						break;
					}
				}
			}
		}
	}
	for(int k = 0; k < borderList.size(); k++){
		pii bd = borderList[k];
		if(dist[bd.first][bd.second] < INF) return bd;
	}
	return {-1,-1};
}

pii check(){
	for(int k = 0; k < borderList.size(); k++){
		visInd++;
 		bool continueK = false;
		pii pr = borderList[k];
		queue<pii> q; q.push(pr);
		vis[pr.first][pr.second] = visInd;
		dist[pr.first][pr.second] = 0;
		while(!q.empty()){
			pii p = q.front(); q.pop();
			int a = p.first, b = p.second;
			for(int i = 0; i < 4; i++){
				int a0 = a + av[i], b0 = b + bv[i];
				if(!invalid(a0,b0) && tile[a0][b0] != '#' && vis[a0][b0] < visInd && dist[a][b] < distBorder[k]){
					vis[a0][b0] = visInd;
					dist[a0][b0] = dist[a][b] + 1;
					q.push({a0,b0});
					if(tile[a0][b0] == 'M'){
						continueK = true;
						break;
					}
				}
			}
			if(continueK) break;
		}
		if(continueK == false) return pr;
	}
	return {-1,-1};
}
 
int main(){
 
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> tile[i][j];
			if(tile[i][j] == 'A'){
				start = {i,j};
				tile[i][j] = '.';
			} else if(tile[i][j] == 'M'){
				qtM++; monsterList.push_back({i,j});
			}
		}
	}
	if(isBorder(start.first,start.second)){
		cout << "YES\n0\n";
		return 0;
	}
 
	bfs(start.first,start.second);
	
	pii res;
	if(monsterList.size() > borderList.size()){
		res = checkForMonsters();
	} else {
		res = checkForEndings();
	}
	if(res.first == -1 && res.second == -1){
		cout << "NO\n";
	} else {
		cout << "YES\n";
 
		vector<int> pathway;
		while(res != start){
			for(int i = 0; i < 4; i++){
				int pa = prv[res.first][res.second].first, pb = prv[res.first][res.second].second;
				if(pa + av[i] == res.first && pb + bv[i] == res.second){
					pathway.push_back(i);
					res.first -= av[i];
					res.second -= bv[i];
					break;
				}
			}
		}
		cout << pathway.size() << "\n";
		for(int z = pathway.size()-1; z >= 0; z--){
			cout << conv[pathway[z]];
		}
		cout << "\n";
	}
 
	return 0;
}