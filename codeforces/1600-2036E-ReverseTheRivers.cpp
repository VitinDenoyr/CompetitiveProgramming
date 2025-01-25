//https://codeforces.com/problemset/problem/2036/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1000000000009ll;

void solve(){
	int n,k,q; cin >> n >> k >> q;
	vector<vector<ll>> line (n+1, vector<ll>(k+1, 0));
	vector<vector<ll>> upd (k+1, vector<ll>(n+1, 0)); //upd é crescente pq bitwise or

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			cin >> line[i][j];
		}
	}
	for(int j = 1; j <= k; j++){
		ll acc = 0;
		for(int i = 1; i <= n; i++){
			acc = acc | line[i][j];
			upd[j][i] = acc;
		}
	}

	for(int qi = 1; qi <= q; qi++){
		int m; cin >> m;
		int limInf = 1, limSup = n;
		int broke = 0;
		for(int i = 1; i <= m; i++){
			ll rg,v; char op;
			cin >> rg;
			cin >> op;
			cin >> v;
			if(op == '>'){
				//acha o menor cara maior que isso ai e seta como limInf
				int l = limInf,r = limSup;
				while(l < r){
					int mid = (l+r)/2;
					if(upd[rg][mid] <= v){
						l = mid+1;
					} else {
						r = mid;
					}
				}
		
				limInf = l;
				if(limInf >= limSup && upd[rg][limInf] <= v){
					broke = 1;
					continue;
				}
			} else { //<
				//acha o maior cara menor que isso ai e seta como limSup
				int l = limInf,r = limSup;
				while(l < r){
					int mid = (l+r+1)/2;
					if(upd[rg][mid] >= v){
						r = mid-1;
					} else {
						l = mid;
					}
				}
	
				limSup = r;
				if(limInf == limSup && upd[rg][limInf] >= v){
					broke = 1;
					continue;
				}
			}
		}
		if(broke){
			cout << "-1\n";
		} else {
			cout << limInf << "\n";
		}
	}
}

int main(){

	solve();

	return 0;
}