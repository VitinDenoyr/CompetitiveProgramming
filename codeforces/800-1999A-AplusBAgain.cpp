//https://codeforces.com/problemset/problem/1999/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	int t,k; cin >> t;
	for(int i = 0; i < t; i++){
		cin >> k;
		cout << k%10 + (k - k%10)/10 << endl;
	}

	return 0;
}