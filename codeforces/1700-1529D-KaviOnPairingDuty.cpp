#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 998244353;
vector<ll> divs, dp;

int main(){

	int n; cin >> n;
	divs = vector<ll> (n+1, 0); dp = vector<ll> (n+1, 0);
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j += i){
			divs[j]++;
		}
	}

	ll sumDp = 1; dp[1] = 1;
	for(int i = 2; i <= n; i++){
		dp[i] = (sumDp + divs[i]) % mod;
		sumDp = (sumDp + dp[i]) % mod;
	}
	cout << dp[n] << "\n";

	return 0;
}



//_ ....... _ K
//1 e 2n - (i-1) = 1 + (2n-i)
//2n-1 e i-1 


//i-1 == 2n-i+1
//2i == 2n+2
//i == n+1
//2 -> 2   3 -> 4   4 -> 6
//2(N-1)
//_ . . _ . . . .

