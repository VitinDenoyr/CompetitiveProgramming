#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,k; vector<ll> v;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(),v.end());
	ll lim = 1;
	if(v[0] != 1){
		cout << 1 << "\n";
	} else {
		for(ll i = 1; i < n; i++){ //Es
			if(v[i] <= lim+1){
				lim += v[i];
				if(i == n-1) cout << lim+1 << "\n";
			} else {
				cout << lim+1 << "\n";
				break;
			}
		}
		
	}

	return 0;
}