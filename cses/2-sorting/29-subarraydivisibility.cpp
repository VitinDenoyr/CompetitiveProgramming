#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define slast s[s.size()-1]

ll mod(ll k, ll md){
	ll r = k%md;
	while(r < 0) r+=md;
	return r;
}

int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	vector<ll> v, s;
	map<ll,ll> qt;

	ll n, sm, val, resp = 0; cin >> n;
	v.push_back(0); s.push_back(0);
	qt[0]++;

	for(int i = 0; i < n; i++){
		cin >> val;
		v.push_back(val);
		s.push_back(val + slast);
		resp += qt[mod(slast,n)];
		qt[mod(slast,n)]++;
	}
	cout << resp << "\n";
 
	return 0;
}
