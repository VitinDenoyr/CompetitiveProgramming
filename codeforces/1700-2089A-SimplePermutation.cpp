//https://codeforces.com/problemset/problem/2089/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	if(n <= 5){
		for(int i = 1; i <= n; i++){
			cout << i << " \n"[i==n];
		}
	} else {
		vector<int> isPrime (n+1, 1); isPrime[1] = 0;
		int chPrime = 2;
		for(int i = 2; i <= n; i++){
			if(!isPrime[i]) continue;
			for(int j = 2*i; j <= n; j += i){
				isPrime[j] = 0;
			}
		}
		for(int i = 3; i <= n; i++){
			if(isPrime[i] && abs((n/2)-i) <= abs((n/2)-chPrime)) chPrime = i;
		}

		int l1 = chPrime-1, l2 = n-chPrime;
		cout << chPrime << " ";
		if(l1 < l2){
			for(int i = 1; i <= l1; i++){
				cout << chPrime - i << " " << chPrime + i << " ";
			}
			for(int i = chPrime + l1+1; i <= n; i++){
				cout << i << " ";
			}
			cout << "\n";
		} else {
			for(int i = 1; i <= l2; i++){
				cout << chPrime - i << " " << chPrime + i << " ";
			}
			for(int i = 1; i <= chPrime - l2 - 1; i++){
				cout << i << " ";
			}
			cout << "\n";
		}
	}
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}