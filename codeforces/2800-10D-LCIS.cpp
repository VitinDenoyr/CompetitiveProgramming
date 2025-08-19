//https://codeforces.com/problemset/problem/10/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	ll n; cin >> n;
	vector<ll> a (n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	ll m; cin >> m;
	vector<ll> b (m+1, 0);
	for(int i = 1; i <= m; i++){
		cin >> b[i];
	}

	//(tamanho máximo,i anterior,j anterior) de alguem que acaba em a[i] = b[j]
	vector<vector<vector<int>>> sz (n+1 , vector<vector<int>> (m+1 , {0,0,0}));

	//tamanho máximo de alguem que acaba em b[j], qual i dele
	vector<pii> mx (m+1, {0,0});

	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 1; j--){
			if(a[i] != b[j]) continue;
			int cur = 0, ii = 0, jj = 0;
			for(int k = 1; k < j; k++){
				if(b[k] < b[j] && cur < mx[k].first){
					cur = mx[k].first;
					ii = mx[k].second;
					jj = k;
				}
			}
			sz[i][j] = {cur+1,ii,jj};
			if(cur+1 > mx[j].first){
				mx[j] = {cur+1, i};
			}
		}
	}

	int mj = 0;
	for(int i = 1; i <= m; i++){
		if(mx[i].first > mx[mj].first){
			mj = i;
		}
	}

	cout << mx[mj].first << "\n";
	int res = mx[mj].first;
	vector<int> resp (res + 1, 0);
	for(int z = 1; z <= res; z++){
		resp[res+1-z] = b[mj];
		mj = sz[mx[mj].second][mj][2];
	}
	for(int z = 1; z <= res; z++){
		cout << resp[z] << " \n"[z==res];
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t = 1;
	while (t--){
		solve();
	}
	return 0;

}