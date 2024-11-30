//https://codeforces.com/contest/264/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define ppll pair<pll,pll>
#define MAXN 100005
#define MAXQ 505
#define INF 100000000000000005
 
ll color[MAXN], value[MAXN];
 
int main(){
 
	int n,q; cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> value[i];
	}
	for(int i = 0; i < n; i++){
		cin >> color[i];
	}
	for(int iq = 0; iq < q; iq++){
		ll a,b; cin >> a >> b;
		vector<ll> dp (MAXN, -INF);
		ll m1 = 0, m2 = 0;
		for(int i = 0; i < n; i++){
			ll pre = dp[color[i]];
			if(m1 != pre){
				dp[color[i]] = max(dp[color[i]]+a*value[i],dp[color[i]]);
				dp[color[i]] = max(m1+b*value[i],dp[color[i]]);
				m2 = max(m2,dp[color[i]]);
				if(m1 < m2) swap(m1,m2);
			} else {
				dp[color[i]] = max(m1+a*value[i],dp[color[i]]);
				dp[color[i]] = max(m2+b*value[i],dp[color[i]]);
				m1 = max(m1,dp[color[i]]);
			}
		}
		cout << m1 << "\n";
	}
 
	return 0;
}