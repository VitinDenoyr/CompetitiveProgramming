//https://codeforces.com/contest/1996/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1003

int main(){

	int t,n,k;
	char g[MAXN][MAXN];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> k;
		for(int x = 0; x < n; x++){
			for(int y = 0; y < n; y++){
				cin >> g[x][y];
			}
		}
		for(int x = 0; x < n/k; x++){
			for(int y = 0; y < n/k; y++){
				cout << g[x*k][y*k];
			}
			cout << "\n";
		}
	}
	
	return 0;
}