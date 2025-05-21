//https://codeforces.com/gym/105505/problem/J
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	double pi = acos(-1);
	int theta, n; cin >> theta >> n;
	vector<int> h (n+1, 0), pos (n+1, 0);
	vector<pair<int,int>> v;
	for(int i = 1; i <= n; i++){
		cin >> pos[i] >> h[i];
		v.push_back({pos[i],h[i]});
	}

	sort(v.begin(),v.end());
	double dist = 0;
	double peak = 0;
	for(int i = 0; i < n; i++){
		double s = (double)v[i].second / tan(theta * pi / 180);
		dist += (s - max(min(peak,v[i].first + s) - v[i].first, 0.0));
		peak = max(peak, s + v[i].first); 
	}

	cout << fixed << setprecision(13) << dist << "\n";	

}

int main(){

	solve();
	return 0;

}