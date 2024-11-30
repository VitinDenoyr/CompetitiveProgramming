//https://codeforces.com/contest/2008/problem/H
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,q;
vector<int> v, freq, pref, ans;

int count(int siz, int x){
	int resp = pref[siz];
	for(int k = 1; k*x <= n; k++){ //conta quantos tem em [k*x, k*x+siz]
		resp += pref[min(k*x+siz,n)] - pref[k*x-1];
	}
	return resp;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t; cin >> t;
	while(t--){
		cin >> n >> q;
		v = vector<int> (n+1,0), freq = vector<int> (n+1,0), pref = vector<int> (2*n+1,0), ans = vector<int> (n+1,0);
		for(int i = 1; i <= n; i++){
			cin >> v[i];
			freq[v[i]]++;
		}
		for(int i = 1; i <= n; i++){
			pref[i] = pref[i-1] + freq[i];
		}
		for(int x = 1; x <= n; x++){
			int l = 0, r = x-1;
			while(l < r){
				int mid = (l+r)/2;
				int podeMediana = count(mid,x);
				if(podeMediana > n/2){
					r = mid;
				} else {
					l = mid+1;
				}
			}
			ans[x] = l;
		}
		for(int i = 1; i <= q; i++){
			int x; cin >> x;
			cout << ans[x] << " \n"[i == q];
		}
	}

	return 0;
}