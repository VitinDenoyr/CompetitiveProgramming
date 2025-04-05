//https://codeforces.com/problemset/problem/2091/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
 
void solve(){
 
	int n; cin >> n;
	if(n%2 == 0){
		cout << -1 << "\n";
	} else {
		for(int i = 1; i <= (n+1)/2; i++){
			cout << 2*i-1 << " ";
		}
		for(int i = 2; i <= n; i += 2){
			cout << i << " \n"[i==(n-1)];
		}
	}
	//0 + 1 ... + 2n-1 =  (4k+1)*(4k+2)/2 = (2k+1)(4k+1) = par
	//135
}
 
int main(){
 
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}
 
	return 0;
}