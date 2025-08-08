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

bool pref(vector<int> a, vector<int> b){
	return a[0] > b[0];
}

void solve(){
	string s; cin >> s;
	int n = s.length();
	int m; cin >> m;
	vector<vector<int>> q;
	vector<int> ans (m+1, 0);

	for(int i = 1; i <= m; i++){
		int l,r; cin >> l >> r;
		q.push_back({l,r,i});
	}
	sort(q.begin(),q.end(),pref);

	Fenwick ftree (n);
	stack<int> awaiting;
	int ri = n, le = n+1;

	for(int i = 0; i < q.size(); i++){
		if(q[i][0] < le){
			for(int j = le-1; j >= q[i][0]; j--){
				if(s[j-1] == ')'){
					awaiting.push(j);
				} else if(awaiting.size() > 0){
					int x = awaiting.top(); awaiting.pop();
					ftree.update(x);
				}
			}
			le = q[i][0];
		}
		ans[q[i][2]] = 2*ftree.query(q[i][1]); 
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << "\n";
	}

}

int main(){

	//ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; t = 1;
	while (t--){
		solve();
	}
	return 0;

}