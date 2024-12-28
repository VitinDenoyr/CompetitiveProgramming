#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1000000007;

struct SegTree {
	int len; vector<int> v;

	SegTree(int n, vector<int>& vec){
		len = n; v = vector<int>(4*n+1);
		build(1,len,1,vec);
	}

	void build(int l, int r, int id, vector<int>& vec){
		if(l == r){
			v[id] = vec[l];
			return;
		}
		build(l,(l+r)/2,2*id,vec);
		build((l+r)/2+1,r,2*id+1,vec);
		v[id] = min(v[2*id],v[2*id+1]);
	}

	void update(int pos, int val, int l, int r, int id){
		if(l == r){
			v[id] = val; return;
		}
		if(pos <= (l+r)/2){
			update(pos,val,l,(l+r)/2,2*id);
		} else {
			update(pos,val,(l+r)/2+1,r,2*id+1);
		}
		v[id] = min(v[2*id],v[2*id+1]);
	}

	int query(int x1, int xn, int l, int r, int id){
		if(l > xn || r < x1) return INF;
		if(x1 <= l && r <= xn) return v[id];
		int a = query(x1,xn,l,(l+r)/2,2*id);
		int b = query(x1,xn,(l+r)/2+1,r,2*id+1);
		return min(a,b);
	}

};

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, q; cin >> n >> q;
	vector<int> v (n+1, 0);

	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}
	SegTree st (n,v);

	for(int i = 1; i <= q; i++){
		int t, a, b; cin >> t >> a >> b;
		if(t == 1){
			st.update(a,b,1,n,1);
		} else {
			cout << st.query(a,b,1,n,1) << "\n";
		}
	}

	return 0;
}