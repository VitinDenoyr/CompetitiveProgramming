//https://codeforces.com/problemset/problem/2060/F
//ATUALIZA O DOC E O GITHUB LINK
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;

void solve(){
	ll n,k; cin >> k >> n;
	
	vector<vector<ll>> dp (k+1, vector<ll>(18, 0));
	for(int i = 2; i <= k; i++){
		dp[i][1] = 1;
	}

	function<ll(ll,ll)> choose, fexpo;

	fexpo = [&](ll a, ll b){
		ll r = 1;
		while(b > 0){
			if(b%2){
				r = (r*a)%mod;
				b--;
			} else {
				a = (a*a)%mod;
				b /= 2;
			}
		}
		return r;
	};

	choose = [&](ll a, ll b){
		if(a < b) return 0ll;
		b = min(b, a - b);
		ll ans = 1;
		for(ll y = 1; y <= b; y++){
			ans = (ans*(a+1ll-y))%mod;
			ans = (ans*fexpo(b+1ll-y,mod-2ll))%mod;
		}
		return ans;
	};

	for(int j = 2; j <= 18; j++){ //Se tenho j números
		for(int i = 1; i <= k; i++){ //E produto i
			for(int t = 2*i; t <= k; t += i){ //Atualiza todas as novas possibilidades
				dp[t][j] = (dp[t][j] + dp[i][j-1])%mod;
			}
		}
	}

	cout << n << " \n"[k==1];
	for(int i = 2; i <= k; i++){
		ll rsp = 0;
		for(int j = 1; j <= 17; j++){
			rsp = (rsp + (dp[i][j]*choose(n+1,j+1))%mod)%mod;
		}
		cout << rsp << " \n"[i==k];
	}
}

int main(){

	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}