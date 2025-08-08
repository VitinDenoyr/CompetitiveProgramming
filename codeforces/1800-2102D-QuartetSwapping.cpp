//https://codeforces.com/contest/2102/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

struct Fenwick {
	int len; vector<int> v;
	Fenwick(int _n){
		len = _n;
		v = vector<int>(len+1,0);
	}
	void update(int p){
		while(p <= len){
			v[p]++;
			p += (p&(-p));
		}
	}
	int query(int x){
		int res = 0;
		while(x > 0){
			res += v[x];
			x -= (x&(-x));
		}
		return res;
	}
};

void solve(){

	ll n; cin >> n;
	vector<int> p (n+1, 0), q (n+1, 0);
	vector<int> ev,od;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		if(i%2){
			od.push_back(p[i]);
		} else {
			ev.push_back(p[i]);
		}
	}
	sort(ev.begin(),ev.end());
	sort(od.begin(),od.end());
	for(int i = 1; i <= n; i += 2){
		q[i] = od[i/2];
	}
	for(int i = 2; i <= n; i += 2){
		q[i] = ev[(i-2)/2];
	}

	function<int(vector<int>)> sign = [&](vector<int> v) -> int {
		Fenwick ftree(n); int sum = 0;
		for(int i = 1; i <= n; i++){
			sum += (i - 1 - ftree.query(v[i]));
			ftree.update(v[i]);
		}
		return sum%2;
	};

	if(sign(p) != sign(q)){
		swap(q[n],q[n-2]);
	}

	for(int i = 1; i <= n; i++){
		cout << q[i] << " \n"[i==n];
	}

}

int32_t main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}