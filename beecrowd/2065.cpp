#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int main(){

	int n,m; cin >> n >> m;

	priority_queue<pii,vector<pii>,greater<pii>> pq;

	vector<int> v (n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		pq.push({0,i});
	}

	vector<int> c (m+1, 0);
	for(int i = 1; i <= m; i++){
		cin >> c[i];
		pii nx = pq.top(); pq.pop();
		pq.push({c[i]*v[nx.second]+nx.first,nx.second});
	}

	int mx = 0;
	while(!pq.empty()){
		pii k = pq.top();
		mx = max(k.first,mx);
		pq.pop();
	}

	cout << mx << "\n";

	return 0;

}