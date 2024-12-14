#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll n;
	cin >> n;
	int preset[9] = {0,0,6,28,96,252,550,1056,1848};
	for(ll k = 1; k <= n; k++){
		if(k < 9){
			cout << preset[k] << "\n";
			continue;
		}
		ll resp = 0;
		resp += ((k-4)*(k-4) * (k*k-9))/2;
		resp += (4*(k-4)*(k*k-7))/2;
		resp += ((4 + 4*(k-4))*(k*k-5))/2;
		resp += (8*(k*k-4))/2;
		resp += (4*(k*k-3))/2;
		cout << resp << "\n";
	}

	return 0;
}