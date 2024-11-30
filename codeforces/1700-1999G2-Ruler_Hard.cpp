//https://codeforces.com/problemset/problem/1999/G2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define printvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	for(int it = 0; it < t; it++){
		int l = 1, r = 1000;
		while(l < r){
			int v = r-l+1; int m1, m2;
			if(v%3 == 0){
				m1 = l + (v/3 - 1);
				m2 = (m1+1) + (v/3 - 1);
			} else if(v%3 == 1){
				m1 = l + (v/3);
				m2 = (m1+1) + (v/3);
			} else {
				m1 = l + v/3;
				m2 = r - v/3;
			}
			cout << "? " << m1 << " " << m2 << endl;
			int resp; cin >> resp;
			if(resp == m1*m2){
				l = m2+1;
			} else if(resp == (m1+1)*(m2+1)){
				r = m1;
			} else {
				l = m1+1; r = m2;
			}
		}
		cout << "! " << l << endl;
	}
	//1 2 =  1 2 3
	return 0;
}