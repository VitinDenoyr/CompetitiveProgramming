//https://codeforces.com/problemset/problem/2129/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<int> p (n+1, 0), q (n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> p[i];

	}

	//Mexer no menor melhora a relação.
	for(int i = 1; i <= n; i++){
		int qe = 0, qd = 0;
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			if(p[j] > p[i]){
				if(i < j){
					qd++;
				} else {
					qe++;
				}
			}
		}
		if(qe > qd){
			q[i] = 2*n - p[i];
		} else {
			q[i] = p[i];
		}
	}

	int qinv = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			if(q[i] > q[j]){
				qinv++;
			}
		}
	}
	cout << qinv << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}