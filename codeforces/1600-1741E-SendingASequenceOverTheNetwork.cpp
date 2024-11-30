//https://codeforces.com/contest/1741/problem/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int v[MAXN];
vector<int> inicied[MAXN];
int dp[MAXN][2] = {0};

int main(){
	int t; cin >> t;
	for(int it = 0; it < t; it++){
		int n; cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> v[i];
			if(i+v[i] <= n){
				inicied[i+v[i]].push_back(i);
			}
		}
		dp[1][0] = 0; dp[1][1] = 0; dp[0][0] = 1; dp[0][1] = 1;
		for(int i = 2; i <= n; i++){
			dp[i][1] = 0;
			if(i-v[i]-1 >= 0 && (dp[i-v[i]-1][0] || dp[i-v[i]-1][1])){
				dp[i][1] = v[i];
			}
			dp[i][0] = 0;
			for(int j = 0; j < inicied[i].size(); j++){
				if(dp[inicied[i][j]-1][0] || dp[inicied[i][j]-1][1]){
					dp[i][0] = inicied[i][j];
					break;
				}
			}
			inicied[i].clear();
		}
		if(dp[n][0] > 0 || dp[n][1] > 0){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}

//5 7 8 9 10 3
/*
dp[0][x] = 1; dp[1][x] = 0;
dp[2][1] = 0; dp[2][0] = {ache um cara que se eu voltar 1 -> ele e 1, se eu voltar 2 -> ele e 2, ...} ou seja,  

*/


