//https://codeforces.com/problemset/problem/2008/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	int t; cin >> t;
	while(t--){
		int n; string s;
		cin >> n >> s;
		int sq = (int)floor(pow(n,0.5));
		bool ans = true;
		if(sq*sq == n){
			for(int i = 0; i < sq; i++){
				for(int j = 0+i*sq; j < (i+1)*sq; j++){
					if(i == 0 || i == sq-1){
						if(s[j] != '1'){
							ans = false;
						}
					} else {
						if(j == i*sq || j == (i+1)*sq - 1){
							if(s[j] != '1'){
								ans = false;
							}
						} else {
							if(s[j] != '0'){
								ans = false;
							}
						}
					}
				}
			}
			if(ans){
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		} else {
			cout << "No\n";
		}
	}

	return 0;
}