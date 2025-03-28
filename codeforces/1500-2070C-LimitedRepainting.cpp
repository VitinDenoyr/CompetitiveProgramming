//https://codeforces.com/problemset/problem/2070/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	ll n, k; cin >> n >> k;
	string s; cin >> s;
	vector<ll> a (n, 0); ll summy = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		summy = max(summy, a[i]);
	}

	ll l = 0, r = summy;
	while(l < r){
		ll mid = (l+r)/2;
		
		vector<bool> seq; 
		for(int i = 0; i < n; i++){
			if(a[i] > mid){
				seq.push_back(s[i] == 'B');
			}
		}

		bool state = false; ll uses = 0;
		for(bool bl : seq){
			if(bl == true){
				if(!state){
					state = true;
					uses++;
				}
			} else {
				state = false;
			}
		}
		if(uses <= k){
			r = mid;
		} else {
			l = mid+1;
		}	
	}
	cout << l << "\n";
	
}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}