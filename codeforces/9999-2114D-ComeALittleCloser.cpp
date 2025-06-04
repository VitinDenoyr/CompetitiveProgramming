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
	pqL queue_miny, queue_minx;
	pqG queue_maxy, queue_maxx;
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
		queue_minx.push({x[i],-i});
		queue_maxx.push({x[i],-i});
		queue_miny.push({y[i],i});
		queue_maxy.push({y[i],i});
		if(i != 1){
			queue_minx.pop();
			queue_maxx.pop();
			queue_miny.pop();
			queue_maxy.pop();
		}
	}
 
	if(n == 1){
		cout << 1 << "\n";
		return;
	}
 
	vector<int> o;
	o.push_back(-queue_minx.top().second);
	o.push_back(-queue_maxx.top().second);
	o.push_back(queue_miny.top().second);
	o.push_back(queue_maxy.top().second);
 
	vector<int> minX (6, BIG), maxX (6, 0), minY (6, BIG), maxY (6, 0);
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
		if(dX*dY == (n-1)){
			resp = min(resp, dX*dY+min(dX,dY));
		} else {
			resp = min(resp, dX*dY);
		}
	}
 
	cout << resp << "\n";
 
}
 
int32_t main(){
 
	int t; cin >> t;
	while(t--){
		solve();
	}
 
	return 0;
}