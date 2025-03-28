//https://codeforces.com/problemset/problem/2072/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	ll n; cin >> n;
	vector<ll> a (n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	ll best = 0, bl = 1, br = 1;
	for(int l = 1; l < n; l++){
		int acc = 0;
		for(int r = l+1; r <= n; r++){
			if(a[r] > a[l]){
				acc++;
			} else if(a[r] < a[l]){
				acc--;
			}
			if(acc < best){
				best = acc;
				bl = l;
				br = r;
			}
		}
	}
	cout << bl << " " << br << "\n";
}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}