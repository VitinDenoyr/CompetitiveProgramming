//https://codeforces.com/problemset/problem/2114/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pqL priority_queue<pii,vector<pii>,greater<pii>>
#define pqG priority_queue<pii,vector<pii>,less<pii>>
const ll BIG = 1000000001;
 
void solve(){
 
	int n; cin >> n;
	vector<int> x (n+1, 0), y (n+1, 0);
	pqL pq_miny, pq_minx;
	pqG pq_maxy, pq_maxx;
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
		pq_minx.push({x[i],-i});
		pq_maxx.push({x[i],-i});
		pq_miny.push({y[i],i});
		pq_maxy.push({y[i],i});
		if(i != 1){
			pq_minx.pop();
			pq_maxx.pop();
			pq_miny.pop();
			pq_maxy.pop();
		}
	}
 
	if(n == 1){
		cout << 1 << "\n";
		return;
	}
 
	vector<int> o;
	o.push_back(-pq_minx.top().second);
	o.push_back(-pq_maxx.top().second);
	o.push_back(pq_miny.top().second);
	o.push_back(pq_maxy.top().second);
 
	vector<int> minX (5, BIG), maxX (5, 0), minY (5, BIG), maxY (5, 0);
	for(int j = 0; j < 4; j++){
		for(int i = 1; i <= n; i++){
			if(i != o[j]){
				minX[j] = min(x[i],minX[j]);
				minY[j] = min(y[i],minY[j]);
				maxX[j] = max(x[i],maxX[j]);
				maxY[j] = max(y[i],maxY[j]);
			}
		}
	}
 
	ll resp = (ll)BIG*(ll)BIG;
	for(int j = 0; j < 4; j++){
		ll dX = (ll)(maxX[j] - minX[j] + 1ll);
		ll dY = (ll)(maxY[j] - minY[j] + 1ll);
		//cout << dX << " x " << dY << " -> " << o[j] << "\n";
		if(dX*dY == (n-1)){
			resp = min(resp, dX*dY+min(dX,dY));
		} else {
			resp = min(resp, dX*dY);
		}
	}
 
	cout << resp << "\n";
 
}
 
int32_t main(){
 
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}
 
	return 0;
}