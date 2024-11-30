//https://codeforces.com/problemset/problem/1982/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define prllvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl
#define MAXN 505

ll n,m,k;
bool snowy[MAXN][MAXN];
ll height[MAXN][MAXN];
ll somaLinha[MAXN][MAXN];
ll somaColuna[MAXN][MAXN];
ll somaTab[MAXN][MAXN];

ll mdc(ll a, ll b){
	if(a < b) return mdc(b,a);
	if(b==0) return a;
	return mdc(b,a%b);
}

int main(){

	ll t; cin >> t;
	for(ll it = 0; it < t; it++){
		cin >> n >> m >> k;
		ll totalMdc = 0, totalSumSnow = 0, totalSumNormal = 0;
		for(ll i = 1; i <= n; i++){
			for(ll j = 1; j <= m; j++){
				cin >> height[i][j];
			}
		}
		for(ll i = 1; i <= n; i++){
			for(ll j = 1; j <= m; j++){
				char d;
				cin >> d; snowy[i][j] = (d - '0');
				if(snowy[i][j]){
					totalSumSnow += height[i][j];
				} else {
					totalSumNormal += height[i][j];
				}
				somaLinha[i][j] = somaLinha[i][j-1] + snowy[i][j];
				somaColuna[j][i] = somaColuna[j][i-1] + snowy[i][j];
				somaTab[i][j] = somaTab[i][j-1] + somaColuna[j][i];
				if(i >= k && j >= k){
					ll newv = somaTab[i][j] - somaTab[i-k][j] - somaTab[i][j-k] + somaTab[i-k][j-k];
					totalMdc = mdc(totalMdc, abs(newv - (k*k - newv)));
				}
			}
		}
		if(totalMdc == 1 || abs(totalSumSnow - totalSumNormal) == 0 || (totalMdc != 0 && abs(totalSumSnow - totalSumNormal)%totalMdc == 0)){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}