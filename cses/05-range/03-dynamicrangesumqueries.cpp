#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Fenwick {
	vector<ll> v; int len;
	Fenwick(int n){
		len = n+1;
		v = vector<ll>(len);
	}

	void update(int pos, ll add){
		while(pos < len){
			v[pos] += add;
			pos += pos&(-pos);
		}
	}

	ll query(int pos){
		ll res = 0;
		while(pos > 0){
			res += v[pos];
			pos -= pos&(-pos);
		}
		return res;
	}
};

int main(){

	int n,q; cin >> n >> q;
	vector<ll> v (n+1);
	Fenwick ftree(n);
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		ftree.update(i,v[i]);
	}

	while(q--){
		int t,a,b;
		cin >> t >> a >> b;
		if(t == 1){
			ftree.update(a,b - v[a]);
			v[a] = b;
		} else {
			cout << (ftree.query(b) - ftree.query(a-1)) << "\n";
		}
	}

	return 0;
}