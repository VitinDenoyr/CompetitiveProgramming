//https://codeforces.com/contest/2014/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	int t; cin >> t;
	while(t--){
		int n,k; cin >> n >> k;
		if((((n+1)/2) - ((n-k+1)/2))%2 == 0){ //n-k+1 ... n
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}