//https://codeforces.com/problemset/problem/2052/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<int> f (n+1, 0), con (n+1, 0);
	vector<pii> p (n+1, {0,0});
	for(int i = 1; i <= n; i++){
		cin >> f[i];
		p[n+1-f[i]] = {i,f[i]};
		con[i] = i;
	}

	vector<pii> res;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n-i; j++){
			res.push_back({con[j+1],con[j]});
			int aux = con[j];
			con[j] = con[j+1];
			con[j+1] = aux;
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n-i; j++){
			if(p[j].first > p[j+1].first){
				res.push_back({p[j+1].second,p[j].second});
				pii aux = p[j];
				p[j] = p[j+1];
				p[j+1] = aux;
			}
		}
	}

	cout << res.size() << "\n";
	for(pii c : res){
		cout << c.first << " " << c.second << "\n";
	}
}

int main(){

	solve();
	return 0;

}