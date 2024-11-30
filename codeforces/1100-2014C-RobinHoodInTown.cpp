//https://codeforces.com/contest/2014/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
 
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	vector<int> v(200001,0);
	while(t--){
		int n; cin >> n;
		ll soma = 0;
		map<int,int> freq;
		for(int i = 1; i <= n; i++){
			int re; cin >> re; v[i] = re;
			freq[v[i]]++;
			soma += v[i];
		}
		ll qtd = 0, ind = 1;
		for(auto x : freq){
			qtd += x.second;
			if(qtd > n/2){
				ind = x.first;
				break;
			}
		}
		ll req = (ll)(2*n*ind) + 1ll - soma;
		if(n <= 2){
			cout << -1 << "\n";
		} else {
			cout << max(0ll,req) << "\n";
		}
	}
 
	return 0;
}
