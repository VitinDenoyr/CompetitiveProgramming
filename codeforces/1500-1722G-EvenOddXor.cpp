//https://codeforces.com/problemset/problem/1722/G
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define printvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl
#define MAXN 200005

int v[MAXN];

int main(){

	int t; cin >> t;
	for(int it = 0; it < t; it++){
		int n;
		cin >> n;
		if(n%2 == 0){
			for(int i = 1; i <= n/2; i++){
				v[2*i-2] = i;
				v[2*i-1] = i + (1<<20); 
			}
			if((n/2)%2 == 1){
				v[1] -= (1<<20);
				v[1] += (1<<21);
				v[3] += (1<<21);
			}
		} else {
			for(int i = 1; i <= n/2; i++){
				v[2*i-2] = i;
				v[2*i-1] = i + (1<<20);
			}
			if((n/2)%2 == 1){
				v[n-1] = (1<<20);
			} else {
				v[n-1] = 0;
			}
		}
		for(int i = 0; i < n; i++){
			cout << v[i] << (" \n")[i == n-1];
		}
	}

	return 0;
}