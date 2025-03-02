//https://codeforces.com/problemset/problem/2061/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a (n+1, 0);
		int qt0 = 0, qt1 = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			if(a[i]%2){
				qt1++;
			} else {
				qt0++;
			}
		}
		cout << (qt0 > 0)*(qt1+1) + (qt0 == 0)*(qt1-1) << "\n";
	}
	return 0;
}