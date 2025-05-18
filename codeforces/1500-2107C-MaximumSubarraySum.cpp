//https://codeforces.com/contest/2107/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const ll BAD = -1000000000000000000ll;

void solve(){

	ll n, k; cin >> n >> k;
	vector<ll> a (n+1, 0);
	string s; cin >> s;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	queue<int> pos;

	ll sum = 0, maxsum = 0, locmin = 0;
	for(int i = 1; i <= n; i++){
		if(s[i-1] == '0'){
			pos.push(i);
			sum = 0;
			locmin = 0;
		} else {
			sum += a[i];
			maxsum = max(sum - locmin, maxsum);
			locmin = min(locmin, sum);
		}
	}

	if(maxsum > k){
		cout << "No\n";
		return;
	}

	if(pos.empty()){
		if(maxsum == k){
			cout << "Yes\n";
			for(int i = 1; i <= n; i++){
				cout << a[i] << " \n"[i==n];
			}
			return;
		} else {
			cout << "No\n";
			return;
		}
	}

	ll x1 = pos.front();
	sum = 0, maxsum = 0;
	for(int i = x1+1; s[i-1] == '1'; i++){
		sum += a[i];
		maxsum = max(sum, maxsum);
	}
	sum = 0; ll maxsum2 = 0;
	for(int i = x1-1; i >= 1; i--){
		sum += a[i];
		maxsum2 = max(sum, maxsum2);
	}

	a[x1] = k - maxsum - maxsum2;
	s[x1-1] = '1';
	cout << "Yes\n";
	for(int i = 1; i <= n; i++){
		if(s[i-1] == '0') a[i] = BAD;
		cout << a[i] << " \n"[i==n];
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}