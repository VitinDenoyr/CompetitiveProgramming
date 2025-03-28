//https://codeforces.com/contest/2064/problem/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define DEB if(0) cout

void solve(){

	int n,k; cin >> n >> k;
	vector<int> a (n+1), qt (n+1, 0);
	vector<int> Lrem (n+1, 0), Rrem (n+1, 0);
	vector<int> starty (n+1, 0), endy (n+1, 0);
	vector<int> point (n+1, 0);

	for(int i = 1; i <= n; i++){
		cin >> a[i];
		qt[a[i]]++;
	}

	int ptrr = 1;
	for(int i = 1; i <= n; i++){
		if(qt[i] > 0){
			point[i] = ptrr;
			ptrr += qt[i];
		}
	}

	vector<int> ng (n+1, n+1), ngO (n+1, n+1), nl (n+1, n+1), pl (n+1, 0), pg (n+1, 0);
	vector<int> Lgroup (n+1, 0), Rgroup (n+1, 0), pointLG (n+1, 0), pointRG (n+1, 0);
	vector<int> LgroupOf (n+1, 0), RgroupOf (n+1, 0), qtLG (n+1, 0), qtRG (n+1, 0);

	stack<pii> st_ng, st_nl, st_pl, st_pg;

	vector<int> stacktop (n+1, 0);
	st_pl.push({0,0});
	for(int i = 1; i <= n; i++){
		while(st_pl.top().first >= a[i]){
			st_pl.pop();
		}
		pl[i] = st_pl.top().second;
		st_pl.push({a[i],i});

		if(Lrem[a[i]] > 0 && pl[stacktop[a[i]]] == pl[i]){
			LgroupOf[i] = LgroupOf[stacktop[a[i]]];
			qtLG[LgroupOf[i]]++;
		} else {
			LgroupOf[i] = i;
			qtLG[LgroupOf[i]]++;
		}
		stacktop[a[i]] = i;
		starty[point[a[i]] + Lrem[a[i]]] = i;
		Lrem[a[i]]++;
	}
	while(!st_pl.empty()) st_pl.pop();
	stacktop.clear();

	st_nl.push({0,n+1});
	for(int i = n; i >= 1; i--){
		while(st_nl.top().first >= a[i]){
			st_nl.pop();
		}
		nl[i] = st_nl.top().second;
		st_nl.push({a[i],i});
	}
	while(!st_nl.empty()) st_nl.pop();

	st_pg.push({n+1,0});
	for(int i = 1; i <= n; i++){
		while(st_pg.top().first <= a[i]){
			st_pg.pop();
		}
		pg[i] = st_pg.top().second;
		st_pg.push({a[i],i});
	}
	while(!st_pg.empty()) st_pg.pop();

	stacktop = vector<int> (n+1, 0);
	st_ng.push({n+1,n+1});
	for(int i = n; i >= 1; i--){
		while(st_ng.top().first <= a[i]){
			st_ng.pop();
		}
		ng[i] = st_ng.top().second;
		ngO[i] = st_ng.top().second;
		st_ng.push({a[i],i});

		if(Rrem[a[i]] > 0 && ngO[stacktop[a[i]]] == ng[i]){
			ng[i] = stacktop[a[i]];
			RgroupOf[i] = RgroupOf[stacktop[a[i]]];
			qtRG[RgroupOf[i]]++;
		} else {
			RgroupOf[i] = i;
			qtRG[RgroupOf[i]]++;
		}

		stacktop[a[i]] = i;
		endy[point[a[i]] + Rrem[a[i]]] = i;
		Rrem[a[i]]++;
	}
	while(!st_ng.empty()) st_ng.pop();

	int ptL = 1, ptR = 1;
	for(int i = 1; i <= n; i++){
		if(qtLG[i] > 0){
			pointLG[i] = ptL;
			ptL += qtLG[i];
		}
		if(qtRG[i] > 0){
			pointRG[i] = ptR;
			ptR += qtRG[i];
		}
	}

	for(int i = 1; i <= n; i++){
		Lgroup[pointLG[LgroupOf[i]]] = i;
		pointLG[LgroupOf[i]]++;
	}

	for(int i = n; i >= 1; i--){
		Rgroup[pointRG[RgroupOf[i]]] = i;
		pointRG[RgroupOf[i]]++;
	}

	ll resp = 0;
	for(int esq = 1; esq <= n; esq++){
		int dir = k - esq;
		if(dir > n || Lrem[esq] == 0 || Rrem[dir] == 0) continue;
		
		while(Lrem[esq] > 0 && Rrem[dir] > 0){
			int x = starty[point[esq] + (qt[esq] - Lrem[esq])];
			int y = endy[point[dir] + Rrem[dir] - 1];

			if(y <= x){
				Rrem[dir]--;
				continue;
			}

			if(y <= nl[x]){
				int l = pointLG[LgroupOf[x]]-qtLG[LgroupOf[x]], r = pointLG[LgroupOf[x]]-1;
				while(l < r){
					int mid = (l+r+1)/2;
					if(Lgroup[mid] < y){
						l = mid;
					} else {
						r = mid-1;
					}
				}
				int x0 = resp;
				resp += ((ll)(Lgroup[l] - pl[x])) * ((ll)(ng[y] - y));
				Rrem[dir]--;
				
			} else {
				if(pg[y] >= nl[x]){
					for(int u = 1; u <= qtLG[LgroupOf[x]]; u++){
						Lrem[esq]--;
					}
				} else {
					int Rsz = ng[Rgroup[pointRG[RgroupOf[y]] - qtRG[RgroupOf[y]]]] - y;
					int Lsz = Lgroup[pointLG[LgroupOf[x]]-1] - pl[x];

					resp += ((ll)Rsz) * ((ll)Lsz);
					for(int u = 1; u <= qtLG[LgroupOf[x]]; u++){
						Lrem[esq]--;
					}
				}
			}
		}
	}
	cout << resp << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}