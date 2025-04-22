#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>

void solve(){

	ll keyA = 0, keyB = 0;
	for(int i = 0; i < 30; i++){
		if(i%2 == 0){
			keyA += (1ll<<i);
		} else {
			keyB += (1ll<<i);
		}
	}

	ll ansA, ansB;
	cout << keyA << "\n";
	cin >> ansA;
	cout << keyB << "\n";
	cin >> ansB;
	cout << "!\n";

	ll dA = ansA - 2ll*(keyA), dB = ansB - 2ll*(keyB);
	ll xA = 0, xB = 0;

	for(int i = 1; i < 30; i += 2){
		if((dA&(1ll<<i)) != 0){ //só um tem digito i
			xA += (1ll<<(i));
		} else {
			if((dA&(1ll<<(i+1))) != 0){ //os dois tem dígito i
				xA += (1ll<<(i));
				xB += (1ll<<(i));
			} //c.c. nenhum tem dígito i
		}
	}

	for(int i = 0; i < 30; i += 2){
		if((dB&(1ll<<i)) != 0){ //só um tem digito i
			xA += (1ll<<(i));
		} else {
			if((dB&(1ll<<(i+1))) != 0){ //os dois tem dígito i
				xA += (1ll<<(i));
				xB += (1ll<<(i));
			} //c.c. nenhum tem dígito i
		}
	}

	ll m; cin >> m;
	cout << (ll)((m|xA) + (m|xB)) << "\n";

}

int main(){
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}