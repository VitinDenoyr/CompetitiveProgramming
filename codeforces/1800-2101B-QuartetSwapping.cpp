#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<int> a (n+1, 0);
	vector<int> imp, par;
	vector<int> pos (n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pos[a[i]] = i;
		if(i%2){
			imp.push_back(a[i]);
		} else {
			par.push_back(a[i]);
		}
	}
	sort(imp.begin(),imp.end());
	sort(par.begin(),par.end());
	int sign = 1, sign2 = 1;
	if(n%2 == 0){
		for(int i = 0; i < imp.size(); i++){
			if(pos[imp[i]] != 2*i+1){
				sign *= -1;
				swap(pos[imp[i]],pos[a[2*i+1]]);
				swap(a[2*i+1],a[pos[a[2*i+1]]]);
			}
		}
		for(int i = 0; i < par.size(); i++){
			if(pos[par[i]] != 2*i+2){
				sign2 *= -1;
				swap(pos[par[i]],pos[a[2*i+2]]);
				swap(a[2*i+2],a[pos[a[2*i+2]]]);
			}
		}
		if(sign != sign2) swap(a[n],a[n-2]);
		for(int i = 1; i <= n; i++){
			cout << a[i] << " \n"[i==n];
		}
	} else {
		for(int i = 0; i < par.size(); i++){
			if(pos[par[i]] != 2*i+2){
				sign *= -1;
				swap(pos[par[i]],pos[a[2*i+2]]);
				swap(a[2*i+2],a[pos[a[2*i+2]]]);
			}
		}
		for(int i = 0; i < imp.size(); i++){
			if(pos[imp[i]] != 2*i+1){
				sign2 *= -1;
				swap(pos[imp[i]],pos[a[2*i+1]]);
				swap(a[2*i+1],a[pos[a[2*i+1]]]);
			}
		}
		if(sign != sign2) swap(a[n],a[n-2]);
		for(int i = 1; i <= n; i++){
			cout << a[i] << " \n"[i==n];
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