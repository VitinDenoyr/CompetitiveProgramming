//https://codeforces.com/contest/2090/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

void solve(){

	ll n; cin >> n;

	vector<int> x (n+1, 0), y (n+1, 0);
	
	int diag = 1, c = 1;
	priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;

	function<int()> view = [&]() -> int{
		int l = diag+1-c;
		return 3*l-2 + 3*c-2;
	};

	function<pii()> newt = [&]() -> pii{
		int l = diag+1-c;
		pq.push({3*l-1+3*c-2,3*c-2,3*l-1});
		pq.push({3*l-2+3*c-1,3*c-1,3*l-2});
		pq.push({3*l+3*c,3*c-1,3*l-1});
		pii p = {3*c-2,3*l-2};
		if(l == 1){
			diag++;
			c = 1;
		} else {
			c++;
		}
		return p;
	};

	for(int i = 1; i <= n; i++){
		int h; cin >> h;
		if(h == 0 || pq.empty()){
			pii re = newt();
			y[i] = re.second; x[i] = re.first;
		} else {
			if(view() < pq.top()[0] || (view() == pq.top()[0] && 3*(c)-2 < pq.top()[1]) || (view() == pq.top()[0] && 3*(c)-2 == pq.top()[1] && 3*(diag+1-c)-2 < pq.top()[2])){
				pii re = newt();
				y[i] = re.second; x[i] = re.first;
			} else {
				y[i] = pq.top()[2]; x[i] = pq.top()[1];
				pq.pop();
			}
		}
		cout << x[i] << " " << y[i] << "\n";
	}
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}