//https://codeforces.com/contest/1996/problem/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define printvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl

int main(){

	ll t;
	cin >> t;
	for(int it = 0; it < t; it++){
		ll n,k,score=0,mv=0;
		cin >> n >> k;
		ll sub[n], val[n];
		for(int i = 0; i < n; i++){
			cin >> val[i];
			mv = max(mv,val[i]);
		}
		for(int i = 0; i < n; i++){
			cin >> sub[i];
		}
		
		ll l = 1, r = mv, op = 0;
		while(l <= r){
			ll mid = (l+r+1)/2, qop = 0;
			for(int i = 0; i < n; i++){ //Se decresci até passar de mid, quantas operações eu fiz?
				if(val[i] < mid) continue;
				qop += (val[i] - mid + sub[i])/sub[i];
			}
			op = qop;
			if(l == r || qop == k){
				l = mid; r = mid; break;
			}
			if(qop < k){
				r = mid-1;
			} else {
				l = mid;
			}
		}
		//agora eu sei que tenho que fazer até passar de l
		for(int i = 0; i < n; i++){ //Qual o score disso?
			if(val[i] < l) continue;
			ll a1 = l + (val[i] - l + sub[i])%sub[i], an = val[i];
			score += ((a1+an)*((an - a1)/sub[i] + 1))/2;
		}
		if(k < op) score -= (op-k)*l;
		cout << score << "\n";
	}

	return 0;
}