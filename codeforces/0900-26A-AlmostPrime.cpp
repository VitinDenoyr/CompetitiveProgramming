//https://codeforces.com/contest/26/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<int> lpdiv (n+1, 0);
	vector<int> primes;
	for(int i = 2; i <= n; i++){
		if(lpdiv[i] == 0){
			lpdiv[i] = i;
			primes.push_back(i);
		
			for(int j = 2*i; j <= n; j += i){
				lpdiv[j] = i;
			}
		}
	}

	int k = 0;
	for(int i = 4; i <= n; i++){
		int z = 0;
		for(int p : primes){
			if(i%p == 0) z++;
		}
		if(z == 2) k++;
	}

	cout << k << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t = 1;
	while (t--){
		solve();
	}
	return 0;

}