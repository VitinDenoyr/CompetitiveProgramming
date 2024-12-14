//https://codeforces.com/contest/1996/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define printvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl

int main(){

	int t,n;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		cout << (n-n%4)/4 + (n%4)/2 << "\n";
	}

	return 0;
}