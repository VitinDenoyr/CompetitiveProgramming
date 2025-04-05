//https://codeforces.com/problemset/problem/2091/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
 
void solve(){
 
	int n, m, k; cin >> n >> m >> k;
	int maxi = (k+n-1)/n; // uma mesa com maxi
	int l = 1, r = maxi;
	while(l < r){
		int mid = (l+r)/2;
		int kk = ((m+1)/(mid+1))*mid + max(m - ((m+1)/(mid+1))*(mid+1), 0);
		if(maxi <= kk){
			r = mid;
		} else {
			l = mid+1;
		}
	}
	cout << l << "\n";
 
}
 
int main(){
 
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}
 
	return 0;
}