//https://codeforces.com/problemset/problem/1999/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	int t; cin >> t;
	for(int i = 0; i < t; i++){
		int a[2],b[2],r = 0;
		cin >> a[0] >> a[1] >> b[0] >> b[1];
		for(int p = 0; p <= 1; p++){
			for(int q = 0; q <= 1; q++){
				if(((a[p] > b[q]) + (a[1-p] > b[1-q]) - (b[p] > a[q]) - (b[1-p] > a[1-q])) > 0){
					r++;
				}
			}
		}
		cout << r << endl;
	}

	return 0;
}