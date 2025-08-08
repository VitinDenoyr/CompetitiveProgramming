#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<bitset<60>> c (n+1, 0);
	for(int i = 1; i <= n; i++){
		int m; cin >> m;
		for(int j = 1; j <= m; j++){
			int k; cin >> k;
			c[i] |= (1ll<<(k-1));
		}
	}
	int q; cin >> q;
	for(int i = 1; i <= q; i++){
		int t,a,b; cin >> t >> a >> b;
		bitset<60> conj;
		if(t == 1){
			conj = (c[a] & c[b]);
		} else {
			conj = (c[a] | c[b]);
		}
		cout << conj.count() << "\n";
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