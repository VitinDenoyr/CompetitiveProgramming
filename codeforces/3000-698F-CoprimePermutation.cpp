//https://codeforces.com/contest/698/problem/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<int> a (n+1, 0);
	int qtz = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == 0) qtz++;
	}

	if(n <= 3){
		int ans = 1;
		for(int i = 1; i <= qtz; qtz++){
			ans *= i;
		}
		cout << ans << "\n";
		return;
	}

	vector<int> isPrime (n+1, 1); isPrime[1] = 0;
	vector<int> qtMult (n+1, 0);
	for(int i = 2; i <= n; i++){
		if(!isPrime[i]) continue;
		qtMult[i]++;
		for(int j = 2*i; j <= n; j += i){
			isPrime[j] = 0;
			qtMult[i]++;
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