#include <bits/stdc++.h>
using namespace std;

int n,cap,priceSum = 0,maxi = 0;
vector<int> price, pages, dp;
 
int main(){

	cin >> n >> cap;
	price = vector<int> (n+1, 0);
	pages = vector<int> (n+1, 0);
	dp = vector<int> (cap+1, 0);

	for(int i = 1; i <= n; i++) cin >> price[i];
	for(int i = 1; i <= n; i++) cin >> pages[i];

	for(int i = 1; i <= n; i++){
		priceSum += price[i];
		for(int j = min(priceSum,cap); j >= price[i]; j--){
			dp[j] = max(dp[j-price[i]] + pages[i],dp[j]);
			maxi = max(maxi, dp[j]);
		}
	}
	cout << maxi << "\n";
 
    return 0;
}