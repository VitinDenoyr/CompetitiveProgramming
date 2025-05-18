//https://codeforces.com/problemset/problem/2103/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<pii> a;
	for(int i = 1; i <= n; i++){
		a.push_back({i,i});
		cin >> a[i-1].second;
	}
	vector<int> assoc (n+1, 0);

	int nextfree = 1, lastfree = n;

	function<int(vector<pii>,int)> calc = [&](vector<pii> v, int it) -> int {
		vector<pii> b; deque<int> dq;
		bool wait = true;
		for(pii p : v){
			if(p.second != it){
				b.push_back(p);
				wait = false;
			} else {
				if(wait){
					dq.push_back(p.first);
				} else {
					dq.push_front(p.first);
				}
			}
		}
		if(it%2 == 1){
			while(!dq.empty()){
				assoc[dq.front()] = lastfree--;
				dq.pop_front();
			}
		} else {
			while(!dq.empty()){
				assoc[dq.front()] = nextfree++;
				dq.pop_front();
			}
		}
		if(b.size() == 1){
			assoc[b[0].first] = nextfree;
			return 0;
		}
		return calc(b,it+1);
	};
	calc(a,1);

	for(int i = 1; i <= n; i++){
		cout << assoc[i] << " \n"[i==n];
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