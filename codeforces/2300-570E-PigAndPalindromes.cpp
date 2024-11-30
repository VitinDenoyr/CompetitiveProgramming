//https://codeforces.com/problemset/problem/570/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 502
#define mod 1000000007
char type[MAXN][MAXN];
ll dp[2][MAXN][MAXN] = {0}; //dp[i][j][k] -> Quantos caminhos chegam ate a linha j da diagonal i de modo que tenha um caminho equivalente na linha k da diagonal i do outro lado 

int main(){
	int n,m; cin >> n >> m;
	int pathSize = ((n-1)+(m-1)+1);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> type[i][j];
		}
	}
	
	if(type[1][1] != type[n][m]){
		cout << 0 << "\n";
		return 0;
	}
	
	dp[1][1][n] = 1; dp[1][n][1] = 1;
	ll sum = 0;
	for(int i = 1; i < (n+m)/2; i++){
		for(int j = 1; j <= i; j++){
			for(int k = n; k >= n-i+1; k--){
				if(j > n || i-j+1 > m || k < 1 || m-i+1-k+n < 1) continue;
				//cout << "ja sei que na iteracao da diagonal " << i << ", posso chegar na linha " << j << " com um caminho palindromico na linha " << k << " da diagonal analoga de " << dp[i%2][j][k] << " formas.\n";
				if(dp[i%2][j][k] == 0) continue;
				//cout << (i-j+1 < m) << (m-i+1-k+n > 1) << (type[j][i-j+2] == type[k][m-i-k+n]) << "\n";
				if((i-j+1 < m) && (m-i+1-k+n > 1) && (type[j][i-j+2] == type[k][m-i-k+n])){
					dp[(i+1)%2][j][k] += dp[i%2][j][k];
					dp[(i+1)%2][j][k] %= mod;
					if(i+1 == (n+m)/2 && (k-j == 0 || (m-i-k+n) - (i-j+2) == 0)){
						sum += dp[i%2][j][k];
						sum %= mod;
						//cout << "somei!\n";
					}
					//cout << "daquih, os tiles " << j << "," << i-j+2 << " e " << k << "," << m-i-k+n << " sao iguais!\n";
				}
				//cout << (i-j+1 < m) << (k > 1) << (type[j][i-j+2] == type[k-1][m-i+1-k+n]) << "\n";
				if((i-j+1 < m) && (k > 1) && (type[j][i-j+2] == type[k-1][m-i+1-k+n])){
					dp[(i+1)%2][j][k-1] += dp[i%2][j][k];
					dp[(i+1)%2][j][k-1] %= mod;
					if(i+1 == (n+m)/2 && ((k-1)-j == 0 || (m-i+1-k+n) - (i-j+2) == 0)){
						sum += dp[i%2][j][k];
						sum %= mod;
						//cout << "somei!\n";
					}
					//cout << "daquir, os tiles " << j << "," << i-j+2 << " e " << k-1 << "," << m-i+1-k+n << " sao iguais!\n";
				}
				//cout << (j < n) << (m-i+1-k+n > 1) << (type[j+1][i-j+1] == type[k][m-i-k+n]) << "\n";
				if((j < n) && (m-i+1-k+n > 1) && (type[j+1][i-j+1] == type[k][m-i-k+n])){
					dp[(i+1)%2][j+1][k] += dp[i%2][j][k];
					dp[(i+1)%2][j+1][k] %= mod;
					if(i+1 == (n+m)/2 && (k-(j+1) == 0 || (m-i-k+n) - (i-j+1) == 0)){
						sum += dp[i%2][j][k];
						sum %= mod;
						//cout << "somei!\n";
					}
					//cout << "daki, os tiles " << j+1 << "," << i-j+1 << " e " << k << "," << m-i-k+n << " sao iguais!\n";
				}
				//cout << (j < n) << (k > 1) << (type[j+1][i-j+1] == type[k-1][m-i+1-k+n]) << "\n";
				if((j < n) && (k > 1) && (type[j+1][i-j+1] == type[k-1][m-i+1-k+n])){
					dp[(i+1)%2][j+1][k-1] += dp[i%2][j][k];
					dp[(i+1)%2][j+1][k-1] %= mod;
					if(i+1 == (n+m)/2 && ((k-1)-(j+1) == 0 || (m-i+1-k+n) - (i-j+1) == 0)){
						sum += dp[i%2][j][k];
						sum %= mod;
						//cout << "somei!\n";
					}
					//cout << "dahqui, os tiles " << j+1 << "," << i-j+1 << " e " << k-1 << "," << m-i+1-k+n << " sao iguais!\n";
				}
				dp[i%2][j][k] = 0;
			}
		}
	}
	cout << sum << "\n";

	return 0;
}