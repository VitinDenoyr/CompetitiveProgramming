#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<int> a (n+1 , 0);
	map<int,int> qt; int resp = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		qt[a[i]]++;
		if(qt[a[i]] == 1) resp++;
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