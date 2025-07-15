//https://codeforces.com/problemset/problem/2097/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const ll mod = 1000000007;
 
void solve(){
 
	int n,m,k; cin >> n >> m >> k;
	int lx,ly;
 
	ll qtd = 1;
	int px,py,nx,ny;
	cin >> px >> py;
 
	vector<vector<int>> loop (n+1, vector<int>(m+1, 0)), vis (n+1, vector<int>(m+1, 0)), exist (n+1, vector<int>(m+1, 0));
	vector<vector<vector<vector<int>>>> adj (n+1, vector<vector<vector<int>>> (m+1, vector<vector<int>>()));
	vector<pii> verts;
	vector<int> ares (k+1, 0);
 
	for(int i = 1; i <= k; i++){
		cin >> nx >> ny;
		if(abs(nx-px) + abs(ny-py) != 2){
			qtd = 0;
		} else if(nx == px){
			loop[nx][min(py,ny)+1]++;
			if(loop[nx][min(py,ny)+1] > 1) qtd = 0;
		} else if(ny == py){
			loop[min(px,nx)+1][ny]++;
			if(loop[min(px,nx)+1][ny] > 1) qtd = 0;
		} else {
			if(!exist[px][ny]){
				exist[px][ny] = 1;
				verts.push_back({px,ny});
			}
			if(!exist[nx][py]){
				exist[nx][py] = 1;
				verts.push_back({nx,py});
			}
			adj[px][ny].push_back({nx,py,i});
			adj[nx][py].push_back({px,ny,i});
		}
		px = nx; py = ny;
	}
 
	int qtv = 0, qta = 0, loops = 0;
	function<void(int,int)> calc = [&](int x, int y){
		vis[x][y] = 1;
		qtv++;
		if(loop[x][y]){
			qta += loop[x][y]; loops = 1;
		}
		for(vector<int> u : adj[x][y]){
			int a = u[0], b = u[1], id = u[2];
			if(!ares[id]){
				ares[id] = 1;
				qta++;
			}
			if(!vis[a][b]){
				calc(a,b);
			}
		}
	};
 
	for(pii v : verts){
		if(qtd == 0) break;
		if(!vis[v.first][v.second]){
			qtv = 0, qta = 0, loops = 0;
			calc(v.first,v.second);
			if(qtv-qta == 1){
				qtd = (qtd * qtv)%mod;
			} else if(qtv == qta && loops == 0){
				qtd = (qtd * 2)%mod;
			} else if(qta > qtv){
				qtd = 0;
			}
		}
	}
 
	cout << qtd << "\n";
 
}
 
int main(){
 
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;
 
}