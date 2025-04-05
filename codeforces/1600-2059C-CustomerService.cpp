//https://codeforces.com/contest/2059/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

void solve(){

	ll n; cin >> n;
	vector<vector<ll>> a (n+1, vector<ll> (n+1, 0));
	vector<ll> qt (n+1, 0), used(n+1, 0);
	map<ll,ll> freq;
	vector<vector<ll>> guys (n+1, vector<ll>());
	for(ll i = 1; i <= n; i++){
		ll qt1 = 0;
		for(ll j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] == 1){
				qt1++;
			} else {
				qt1 = 0;
			}
		}
		qt[i] = qt1;
		freq[qt1]++;
		guys[qt1].push_back(i);
	}

	ll mx = 0;
	for(int i = 0; i <= n; i++){
		if(freq[i] > 0){
			mx = i;
		}
	}
	mx = min(mx,n-1);

	ll alc = 0, nxt = mx, goal = mx;
	for(ll it = n; it >= 0; it--){
		if(nxt <= it){
			alc += freq[it];
			nxt -= freq[it];
		} else { // nxt = it + 1
			nxt--; goal--;
			alc += freq[it];
			nxt -= freq[it];
		}

		if(alc >= mx+1){
			break;
		}
	}

	cout << goal+1 << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}