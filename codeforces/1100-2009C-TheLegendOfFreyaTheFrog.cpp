//https://codeforces.com/problemset/problem/2009/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int t; cin >> t;
	while(t--){
		int x,y,k; cin >> x >> y >> k;
		int qt1 = (x+(k-1))/k;
		int qt2 = (y+(k-1))/k;
		if(qt1 <= qt2){
			cout << 2*qt2 << "\n";
		} else {
			cout << 2*qt1-1 << "\n";
		}
	}
	return 0;
}