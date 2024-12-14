#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define INF 1000
 
int main(){
 
	ll n,lim; cin >> n >> lim;
	ll p[n];
	pll dp[1<<n];
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	sort(p,p+n);
	dp[0] = {0,0};
	for(ll i = 1; i < (1<<n); i++){
	    dp[i] = {INF,0};
		for(int j = 0; j < n; j++){
			ll pwr = (1<<j);
			if(((i^pwr) < i) && dp[i^pwr].first <= dp[i].first){ //j esta presente em i. Vamos ver se pode ser economizado olhando o caso onde ele nao estava presente usando o elevador de la
                if(dp[i^pwr].first <= dp[i].first-2){ //sempre vai dar pra substituir
                    if(dp[i^pwr].second >= p[j]){
                        dp[i] = {dp[i^pwr].first, dp[i^pwr].second - p[j]};
                    } else {
                        dp[i] = {dp[i^pwr].first+1, lim-p[j]};
                    }
                } else if(dp[i^pwr].first == dp[i].first-1){ //da pra substituir se couber no elevador do anterior ou se nao couber mas sobrar mais
                    if(dp[i^pwr].second >= p[j]){
                        dp[i] = {dp[i^pwr].first, dp[i^pwr].second - p[j]};
                    } else {
                        dp[i].second = max(dp[i].second, lim-p[j]);
                    }
                } else { //so da pra substituir se couber no elevador do anterior e ainda sobrar mais
                    if(dp[i^pwr].second - p[j] > dp[i].second){
                        dp[i].second = dp[i^pwr].second - p[j];
                    }
                }
			}
		}
		if(i+1 == (1<<n)){
		    cout << dp[i].first << "\n";
		}
	}
 
	return 0;
}