#include <bits/stdc++.h>
using namespace std;
#define ll long long

int v[200005][31] = {0}; //Time limit apertado, estático é melhor que vector

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n,q; cin >> n >> q;
	map<int,int> mp; mp[1] = 0;

	for(int i = 1; i <= n; i++){
		int d; cin >> d;
		v[i][0] = d;
	}

	for(int p = 1; p <= 30; p++){
		mp[(1<<p)] = p;
		for(int i = 1; i <= n; i++){
			v[i][p] = v[v[i][p-1]][p-1];
		}
	}

	for(int i = 1; i <= q; i++){
		int t, k; cin >> t >> k;
		while(k > 0){
			t = v[t][mp[(k&(-k))]];
			k -= (k&(-k));
		}
		cout << t << "\n";
	}

	return 0;
}