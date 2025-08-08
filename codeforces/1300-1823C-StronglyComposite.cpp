//https://codeforces.com/contest/1823/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	//1, p ou pq não é, c.c. é
	int n; cin >> n;
	vector<int> a (n+1, 0);
	map<int,int> qt;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		for(int j = 2; j*j <= a[i]; j++){
			while(a[i]%j == 0){
				qt[j]++;
				a[i] /= j;
			}
		}
		if(a[i] > 1) qt[a[i]]++;
	}

	int rem = 0, us = 0;
	for(pii p : qt){
		us += (p.second/2);
		rem += (p.second - 2*(p.second/2));
	}
	us += (rem/3);
	cout << us << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}