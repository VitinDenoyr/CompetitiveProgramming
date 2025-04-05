//https://codeforces.com/contest/2091/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
 
void solve(){
 
	ll n, x; cin >> n >> x;
	vector<ll> a (n, 0); int qtd = n, resp = 0, ans = 0;
	priority_queue<int,vector<int>,less<int>> pq;
	for(int i = 1; i <= n; i++){
		cin >> a[i-1];
		pq.push(a[i-1]);
	}
 
	for(int i = 1; i <= n; i++){
		int val = (x+i-1)/i;
		if(pq.empty()) break;
		while(!pq.empty() && pq.top() >= val){
			resp++;
			pq.pop();
		}
		ans += (resp/i);
		resp -= (resp/i)*i;
	}
 
	cout << ans << "\n";
 
}
 
int main(){
 
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}
 
	return 0;
}