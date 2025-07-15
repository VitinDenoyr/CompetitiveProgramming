//https://codeforces.com/problemset/problem/2120/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	ll n,m; cin >> n >> m;
	if(m > n*(n+1)/2 || m < n){
		cout << -1 << "\n";
		return;
	} else {
		vector<int> v;
		for(int i = n; i >= 1; i--){
			if(2*i-1 > m){
				v.push_back(m - (i-1));
				for(int j = 1; j <= i; j++){
					if(j != (m - (i-1))){
						v.push_back(j);
					}
				}
				break;
			} else {
				m -= i;
				v.push_back(i);
			}
		}
		cout << v[0] << "\n";
		for(int i = 1; i < v.size(); i++){
			cout << v[i-1] << " " << v[i] << "\n";
		}
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