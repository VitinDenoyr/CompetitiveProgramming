#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct SegTree {
	int len; vector<ll> v;
	const vector<int>& members;

	SegTree(int _n, const vector<int>& memb)
	: len(_n), members(memb) {
		v = vector<ll> (4*len,0);
		construct(1,len,1);
	}

	void construct(int x1, int xn, int xi){
		if(x1 == xn){
			v[xi] = members[x1];
		} else {
			int mid = (x1+xn)/2;
			construct(x1,mid,2*xi);
			construct(mid+1,xn,2*xi+1);
			v[xi] = v[2*xi]+v[2*xi+1];
		}
	}

	ll query(int l, int r, int x1, int xn, int xi){
		if(x1 > r || xn < l) return 0;
		if(l <= x1 && r >= xn) return v[xi];
		int mid = (x1+xn)/2;
		ll r1 = query(l,r,x1,mid,2*xi), r2 = query(l,r,mid+1,xn,2*xi+1);
		return r1+r2;
	}

	void update(int ind, int val, int x1, int xn, int xi){
		if(x1 != xn){
			int mid = (x1+xn)/2;
			if(ind <= mid){
				update(ind,val,x1,mid,2*xi);
			} else {
				update(ind,val,mid+1,xn,2*xi+1);
			}
			v[xi] = v[2*xi]+v[2*xi+1];
		} else {
			v[xi] = val;
		}
	}
};

int main(){

	int n,q; cin >> n >> q;
	vector<int> v (n+1);
	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}
	SegTree stree(n,v);

	while(q--){
		int t,a,b;
		cin >> t >> a >> b;
		if(t == 1){
			stree.update(a,b,1,n,1);
		} else {
			cout << stree.query(a,b,1,n,1) << "\n";
		}
	}

	return 0;
}