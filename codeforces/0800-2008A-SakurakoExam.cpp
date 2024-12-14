//https://codeforces.com/problemset/problem/2008/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	int t; cin >> t;
	while(t--){
		int a,b,tot=0; cin >> a >> b;
		tot += a; tot += 2*b;
		if(tot%2 == 1 || (a == 0 && b%2 == 1)){
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}

	return 0;
}