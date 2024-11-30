//https://codeforces.com/problemset/problem/2009/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> r;
		for(int i = 0; i < n; i++){
			string s; cin >> s;
			int ind = 0;
			while(s[ind] != '#'){
				ind++;
			}
			r.push_back(ind+1);
		}
		for(int j = r.size()-1; j >= 0; j--){
			cout << r[j] << " \n"[j==0];
		}
	}

	return 0;
}