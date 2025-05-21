//https://codeforces.com/contest/2090/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

void solve(){

	ll n; cin >> n;
	ll nxt = 1, mx = 1, prv = 1;
	priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;
	queue<ll> nm; nm.push(1);
	for(ll i = 1; i <= n; i++){
		nm.push(prv + i);
		prv += i;
	}

	ll tl = 1, tc = 1;
	function<pii()> allocateTable = [&]() -> pii{
		if(nxt == nm.front()){
			tl = mx++, tc = 1;
			nm.pop();
		} else {
			tl--; tc++;
		}
		pq.push({3*(tc+tl-1)-1,3*tc-1,3*tl-2});
		pq.push({3*(tc+tl-1)-1,3*tc-2,3*tl-1});
		pq.push({3*(tc+tl)-1,  3*tc-1,3*tl-1});
		nxt++;
		return {3*tc-2,3*tl-2};
	};

	function<int()> nextSeat = [&]() -> int{
		int tl2, tc2;
		if(nxt == nm.front()){
			tl2 = mx, tc2 = 1;
		} else {
			tl2 = tl - 1; tc2 = tc + 1;
		}
		return (3*tc2-2) + (3*tl2-2) - 1;
	};

	for(ll i = 1; i <= n; i++){
		int a; cin >> a;
		if(a == 0){
			pii x = allocateTable();
			cout << x.first << " " << x.second << "\n";
		} else {
			if(pq.empty() || nextSeat() < pq.top()[0]){
				pii x = allocateTable();
				cout << x.first << " " << x.second << "\n";
			} else {
				cout << pq.top()[1] << " " << pq.top()[2] << "\n";
				pq.pop();
			}
		}
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