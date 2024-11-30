#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll dp[1002][12][1026] = {0}; //dp[a][b][c] -> tem a-1 linhas preenchidas, na a tem b tiles da dir pra esq e de desvio tem c de mask de 'faltantes' = tiles que foi decidido botar pra cima
unordered_map<ll,ll> conv;

int main(){

	ll m,n;
	cin >> m >> n;
	if(n < m){ //Garante M <= N
		ll k = n; n = m; m = k;
	}
	if((m*n)%2){
		cout << 0 << "\n";
		return 0;
	} else if(m == 1){
		cout << 1 - n%2 << "\n";
		return 0;
	}
	for(ll kt = 0; kt < 10; kt++){
		conv[(1 << kt)] = kt;
	}
	dp[1][0][0] = 1;
	for(ll i = 1; i <= n+1; i++){ //10^3
		for(ll j = 0; j <= m-1; j++){ //10
			for(ll st = 0; st < (1<<m); st++){ //10^3
				if(i == 1 && st >= (1<<j)) break; //Impossível faltar na linha 0
				if(j == 0){ //Linha lisa
					if((st&((1<<(m-2)) + (1<<(m-1)))) == 0){ //Pode ter vindo de faltando o último horizontal
						dp[i][j][st] += dp[i-1][m-2][st]; //dp[2][1][0] = 1
						dp[i][j][st] += dp[i-1][m-1][st + (1<<(m-1))]; //dp[2][2][4] = 2
					} else if((st&(1<<(m-1))) != 0){ //Pode ter vindo faltando o último vertical
						dp[i][j][st] += dp[i-1][m-1][st - (1<<m-1)]; //dp[1][1][1] = 1
					} else { //Falta alguém sem ser o último vertical
						dp[i][j][st] += dp[i-1][m-1][st + (1<<m-1)];
					}
					dp[i][j][st] %= mod;
					if(i == n+1 && j == 0 && st == 0){
						i = n+2;
						j = m;
						st = (1 << m);
					}
				} else if(j == 1){ //Linha só tem 1
					if((st&1) == 0){
						dp[i][j][st] += dp[i][0][st + 1];
					} else {
						dp[i][j][st] += dp[i][0][st - 1];
					}
					dp[i][j][st] %= mod;
				} else { //Já decidimos 2 blocos nessa linha
					if((st&((1<<(j-2)) + (1<<(j-1)))) == 0){
						dp[i][j][st] += dp[i][j-2][st]; //dp[2][0][4] = 1
						dp[i][j][st] += dp[i][j-1][st + (1<<(j-1))];
					} else if((st&(1<<(j-1))) != 0){
						dp[i][j][st] += dp[i][j-1][st - (1<<(j-1))];
					} else {
						dp[i][j][st] += dp[i][j-1][st + (1<<(j-1))];
					}
					dp[i][j][st] %= mod;
				}
			}
		}
	}
	dp[n+1][0][0] %= mod;
	cout << dp[n+1][0][0] << "\n";

	return 0;
}

/*
by 1  2  3  4  5  6  7
1 00 01 00 01 00 01 00 
2 01 02 03 05 08 13 21 
3 00 03 00 11 00 .. 00
4 01 05 11 36 .. .. 781 
5 00 08 00 .. 00 .. 00
6 01 13 .. .. .. .. ..
7 00 21 00 781 00 .. 00
*/