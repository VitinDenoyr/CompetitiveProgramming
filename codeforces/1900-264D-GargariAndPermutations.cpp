//https://codeforces.com/contest/264/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005

int s[5][MAXN];
int dp[MAXN] = {0};
bool ant[5][MAXN][MAXN];

int main(){

	int n,k; cin >> n >> k;
	for(int r = 0; r < k; r++){
		for(int i = 0; i < n; i++){
			cin >> s[r][i];
			for(int j = 0; j < i; j++){
				ant[r][s[r][j]][s[r][i]] = 1;
			}
		}
	}
	for(int i = 1; i < n; i++){
		//o cara s[0][i] pertence a sequencia, qual tamanho da maior sub comum ate chegar nele?
		for(int j = 0; j < i; j++){ //vai verificar se ele pode estar com j na sequencia
			bool compatible = true;
			for(int seq = 1; seq < k; seq++){
				compatible = (compatible && ant[seq][s[0][j]][s[0][i]]);
			}
			if(compatible) dp[i] = max(dp[i], dp[j]+1);
		}
	}
	int mdp = 0;
	for(int i = 0; i < n; i++){
		mdp = max(mdp, dp[i]);
	}
	cout << mdp+1 << "\n";

	return 0;
}