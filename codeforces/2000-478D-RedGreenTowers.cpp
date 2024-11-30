//https://codeforces.com/contest/478/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define MAXN 200005

int main(){

	int r,g,h; cin >> r >> g;
	//Encontrarei h
	int l = 1, ri = 999;
	while(l < ri){
		int mid = (l+ri+1)/2;
		if((mid*(mid+1))/2 <= (r+g)){ //existe uma torre de tamanho mid factivel
			l = mid;
		} else {
			ri = mid-1;
		}
	}
	h = l;

	ll sum = 0;
	int dp[MAXN*2] = {1}; //quantos torres tem i blocos vermelhos

	for(int a = 1; a <= h; a++){
		for(int i = min((a*(a+1))/2,r); i >= a; i--){
			dp[i] += dp[i - a]; //dp[i][a] = dp[i][a-1] + dp[i-a][a-1]. dp[i] guardava dp[i][a-1] antes
			dp[i] %= mod;
		}
	}
	for(int i = 0; i <= r; i++){
		if(g >= (h*(h+1))/2 - i){
			sum += dp[i];
			sum %= mod;
		}
	}
	cout << sum << "\n";

	return 0;
}