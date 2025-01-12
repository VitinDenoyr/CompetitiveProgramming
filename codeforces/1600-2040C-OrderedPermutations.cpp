//https://codeforces.com/contest/2040/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void solve(){
	ll n,k; cin >> n >> k;
	if(n <= 61 && k > (1ll<<(n-1))){
		cout << "-1\n"; 
		return;
	}
 
	vector<ll> esq, dir;
	ll acc = 0;
	for(ll i = 1; i <= n-1; i++){ 
		if((n-1-i) <= 60 && k > acc + (1ll<<(n-1-i))){
			dir.push_back(i);
			acc += (1ll<<(n-1-i));
		} else {
			esq.push_back(i);
		}
	}
 
	esq.push_back(n);
	for(ll i = dir.size()-1; i >= 0; i--){
		esq.push_back(dir[i]);
	}
 
	for(ll i = 0; i < esq.size(); i++){
		cout << esq[i] << " \n"[i == (esq.size()-1)];
	}
}
 
int main(){
 
	int t; cin >> t;
	while(t--){
		solve();
	}
 
	return 0;
}