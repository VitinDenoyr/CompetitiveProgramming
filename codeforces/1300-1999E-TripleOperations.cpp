//https://codeforces.com/problemset/problem/1999/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define printvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl

int main(){

	int t; cin >> t;
	for(int it = 0; it < t; it++){
		int a,b;
		cin >> a >> b;
		int lga = 0, lgb = 0;
		int ma = a, mb = b;
		while(ma > 0){
			ma /= 3; lga++;
		}
		while(mb > 0){
			mb /= 3; lgb++;
		}

		int s = lga;
		for(int i = lga; i <= lgb; i++){
			s += (min(pow(3,i),(double)b+1) - max((double)a,pow(3,i-1)))*i;
		}
		cout << s << endl;

	} //se tem lg = k -> eh entre 3^(k-1) <= x < 3^k

	return 0;
}