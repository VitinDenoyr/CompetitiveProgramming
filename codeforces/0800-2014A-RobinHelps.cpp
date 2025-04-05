//https://codeforces.com/contest/2014/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	int t; cin >> t;
	while(t--){
		int n,k,g=0,r=0; cin >> n >> k;
		vector<int> v (n+1,0);
		for(int i = 1; i <= n; i++){
			cin >> v[i];
			if(v[i] >= k){
				g += v[i];
			} else if(v[i] == 0 && g > 0){
				r++; g--;
			}
		}
		cout << r << "\n";
	}

	return 0;
}