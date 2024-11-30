#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll m,n,rd;
	multiset<ll> b;
	cin >> n >> m;
	for(ll i = 0; i < n; i++){ //O(n)
		cin >> rd;
		b.insert(rd);
	}

	for(ll i = 0; i < m; i++){ //O(n)
		cin >> rd;
		auto k = b.upper_bound(rd); //O(logn)
		if(k == b.begin()){
			cout << "-1\n";
		} else{
			--k;
			cout << (*k) << "\n";
			b.erase(k);
		}
	}
	
	return 0;
}