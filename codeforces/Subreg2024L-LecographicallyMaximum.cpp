//https://codeforces.com/gym/105327/problem/L
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int main(){

	int n; cin >> n;
	vector<int> a (n+1, 0);
	vector<int> qt (30, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		for(int b = 0; b < 30; b++){
			if((a[i] & (1<<b)) != 0){
				qt[b]++;
			}
		}
	}

	for(int i = 1; i <= n; i++){
		ll x = 0;
		for(int b = 0; b < 30; b++){
			if(qt[b] > 0){
				x += (1<<b);
				qt[b]--;
			}
		}
		cout << x << " \n"[i==n];
	}

	return 0;

}