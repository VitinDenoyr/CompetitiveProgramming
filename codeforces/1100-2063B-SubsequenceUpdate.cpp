//https://codeforces.com/problemset/problem/2063/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n,l,r; cin >> n >> l >> r;
	vector<int> a (n+1, 0); ll s = 0;
	vector<int> firsts, seconds, thirds;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i >= l && i <= r){
			s += a[i];
			seconds.push_back(a[i]);
		} else if(i < l){
			firsts.push_back(a[i]);
		} else {
			thirds.push_back(a[i]);
		}
	}

	sort(firsts.begin(),firsts.end());
	sort(seconds.begin(),seconds.end());
	sort(thirds.begin(),thirds.end());

	ll s0 = 0, s1 = 0;
	for(int i = 1; i <= min(r-l+1, l-1); i++){ //i-1
		if(firsts[i-1] < seconds[r-l+1-i]){
			s0 += (firsts[i-1] - seconds[r-l+1-i]);
		} else {
			break;
		}
	}

	for(int i = 1; i <= min(r-l+1, n-r); i++){
		if(thirds[i-1] < seconds[r-l+1-i]){
			s1 += (thirds[i-1] - seconds[r-l+1-i]);
		} else {
			break;
		}
	}

	cout << min(s + s0, s + s1) << "\n";
}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}