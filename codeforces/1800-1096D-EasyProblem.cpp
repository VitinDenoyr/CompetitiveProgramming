//https://codeforces.com/contest/1096/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXA 998244353ll
#define MAXN 100005
#define INF MAXA*MAXN

ll cost[MAXN], dp[MAXN][4];

int main(){

	ll n; cin >> n;
	string s; cin >> s;
	for(int i = 0; i < n; i++){
		cin >> cost[i];
		dp[i][0] = INF; dp[i][1] = INF; dp[i][2] = INF; dp[i][3] = INF;
	}
	string hard = "hard";
	//Dp[i][j] -> menor custo considerando ate o caractere i de modo que usou j caracteres de hard
	dp[0][0] = (s[0] == 'h')*(cost[0]);
	if(s[0] == 'h') dp[0][1] = 0;
	for(int i = 1; i < n; i++){
		dp[i][0] = dp[i-1][0] + (s[i] == 'h')*(cost[i]);
		dp[i][1] = min(dp[i-1][1] + (s[i] == 'a')*(cost[i]), dp[i-1][0] + (s[i] != 'h')*(INF));
		dp[i][2] = min(dp[i-1][2] + (s[i] == 'r')*(cost[i]), dp[i-1][1] + (s[i] != 'a')*(INF));
		dp[i][3] = min(dp[i-1][3] + (s[i] == 'd')*(cost[i]), dp[i-1][2] + (s[i] != 'r')*(INF));
	}
	cout << min(min(dp[n-1][0],dp[n-1][1]),min(dp[n-1][2],dp[n-1][3])) << "\n";

	return 0;
}