//https://codeforces.com/problemset/problem/2009/F
#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

int main(){

	ll t; cin >> t;
	while(t--){
		ll n,q,s=0; cin >> n >> q;
		ll sum[n+1] = {0};
		vector<ll> a (n+1); 
		for(ll i = 1; i <= n; i++){
			cin >> a[i];
			s += a[i];
			sum[i] = sum[i-1] + a[i];
		}
		for(ll i = 0; i < q; i++){
			ll l,r; cin >> l >> r;
			ll x1 = ((l+(n-1))/n), x2 = ((r+(n-1))/n); //numero do array clonado que l e r pertencem
			//cout << "arrays " << x1 << " e " << x2 << "\n";
			if(x1 == x2){
				ll cind1 = (l - (x1-1)*n); //indice de 1 a n de l no array clonado
				ll acind1 = cind1 + (x1 - 1); if(acind1 > n) acind1 -= n; //indice no array a que tem o mesmo valor que o valor de l
				
				ll cind2 = (r - (x2-1)*n); //indice do r
				ll acind2 = cind2 + (x2 - 1); if(acind2 > n) acind2 -= n; //analogo

				//o array x1 vai de [x1 ... n],[1 ... x1-1]
				if(acind1 <= acind2){ //alem de estarem no mesmo array, ele vai direto
					cout << sum[acind2] - sum[acind1] + a[acind1] << "\n";
				} else { //ele da ciclo
					cout << ((s - sum[acind1] + a[acind1]) + (sum[acind2])) << "\n";
				}
			} else {
				ll fullarraysum = (x2-x1-1)*(s);
				//cout << "arrays completos dentro: " << fullarraysum << "\n";

				ll cind1 = (l - (x1-1)*n); //indice de 1 a n de l no array clonado
				ll acind1 = cind1 + (x1 - 1); if(acind1 > n) acind1 -= n; //indice no array a que tem o mesmo valor que o valor de l
				//cout << "l tem indice " << cind1 << " em seu array e " << acind1 << " quando converte\n";
				
				ll cind2 = (r - (x2-1)*n); //indice do r
				ll acind2 = cind2 + (x2 - 1); if(acind2 > n) acind2 -= n; //analogo
				//cout << "r tem indice " << cind2 << " em seu array e " << acind2 << " quando converte\n";

				ll sL = s;
				if(cind1 <= acind1){
					//cout << "o indice no subarray eh antes do valor real " << (cind1 == acind1) << "\n";
					sL -= (sum[acind1] - a[acind1]);
					sL += (sum[x1] - a[x1]);
				} else {
					//cout << "o indice no subarray eh dpss do valor real\n";
					sL -= (sum[acind1] - a[acind1]) + (s - sum[x1] + a[x1]);
				}
				//cout << "somarray L: " << sL << "\n";

				ll sR = s;
				if(cind2 <= acind2){
					sR -= (sum[acind2] - a[acind2]);
					sR += (sum[x2] - a[x2]);
				} else {
					sR -= (sum[acind2] - a[acind2]) + (s - sum[x2] + a[x2]);
				}
				sR = s - (sR) + a[acind2];
				//cout << "somarray R: " << sR << "\n";

				cout << sL + sR + fullarraysum << "\n";
				///45 6 78123  ...   7812 3 456
			}
		}
	}

	return 0;
}