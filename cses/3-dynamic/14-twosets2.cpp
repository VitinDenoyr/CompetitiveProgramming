#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 2000000014
#define MAXS 125*501
ll qt[MAXS] = {1}; //Quantos conjuntos tem soma i
 
int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
 
	int n; cin >> n;
	if(n%4 == 2 || n%4 == 1){
		cout << 0 << "\n";
		return 0;
	}
	int lims = n*(n+1)/4;
	for(int i = 1; i <= n; i++){ 
		for(int j = min(i*(i+1)/2,lims); j >= i; j--){
			qt[j] += qt[j-i];
			qt[j] %= mod;
		}
	}
	cout << qt[lims]/2 << "\n";
 
 
	return 0;
}