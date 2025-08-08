//https://codeforces.com/contest/2121/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n,m; cin >> n >> m;
	vector<vector<int>> a (n+1, vector<int>(m+1, 0));
	vector<pii> mxs;
	int mx = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			if(a[i][j] > mx){
				mx = a[i][j];
				mxs.clear();
				mxs.push_back({i,j});
			} else if(a[i][j] == mx){
				mxs.push_back({i,j});
			}
		}
	}

	vector<int> qtl (n+1, 0), qtc (m+1, 0);
	int il = 0, ic = 0, ql = 0, qc = 0;
	if(mxs.size() <= 2){
		cout << mx-1 << "\n";
		return;
	}
	for(pii p : mxs){
		qtl[p.first]++;
		qtc[p.second]++;
		if(qtl[p.first] == 2){
			if(il == 0){
				il = p.first;
			} else {
				cout << mx << "\n";
				return;
			}
		}
		if(qtc[p.second] == 2){
			if(ic == 0){
				ic = p.second;
			} else {
				cout << mx << "\n";
				return;
			}
		}
	}
	if(il == 0 && ic == 0){
		cout << mx << "\n";
		return;
	}
	int qtd = 0;
	if(ic == 0 && il != 0){
		for(pii p : mxs){
			if(p.first != il){
				if(ic == 0 || ic == p.second){
					ic = p.second;
				} else {
					cout << mx << "\n";
					return;
				}
			}
		}
	}
	if(ic != 0 && il == 0){
		for(pii p : mxs){
			if(p.second != ic){
				if(il == 0 || il == p.first){
					il = p.first;
				} else {
					cout << mx << "\n";
					return;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(a[i][ic] == mx) qtd++;
	}
	for(int i = 1; i <= m; i++){
		if(a[il][i] == mx) qtd++;
	}
	if(a[il][ic] == mx) qtd--;

	if(qtd == mxs.size()){
		cout << mx-1 << "\n";
	} else {
		cout << mx << "\n";
	}
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}