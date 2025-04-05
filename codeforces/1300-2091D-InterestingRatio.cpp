//https://codeforces.com/contest/1741/problem/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
 
vector<int> isPrime, qtp;
 
void solve(){
	int n; cin >> n;
 
	ll resp = 0;
	for(int i = 1; i <= n; i++){
		resp += qtp[(n/i)];
	}
 
	cout << resp << "\n";
}
 
int main(){
 
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
 
	isPrime = vector<int> (10000001, 1); isPrime[1] = 0;
	qtp = vector<int> (10000001, 0);
	for(int i = 2; i <= 10000000; i++){
		if(!isPrime[i]){
			qtp[i] = qtp[i-1];
			continue;
		}
		qtp[i] = qtp[i-1] + 1;
		for(int mult = 2*i; mult <= 10000000; mult += i){
			isPrime[mult] = 0;
		}
	}
 
	while(t--){
		solve();
	}
 
	return 0;
}