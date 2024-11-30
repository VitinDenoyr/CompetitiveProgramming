//https://codeforces.com/contest/455/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100002

ll freq[MAXN], save[MAXN]; //save[i] -> Tudo que tenha valor até i foi removido, mas nada que tenha valor até i foi removido
ll qt(ll ind){
	return save[max(ind,(ll)0)];
}

int main(){

    ll n, q;
	ll soma = 0, gtr = 0;
    cin >> n;
    vector<ll> v;

    for(ll i = 0; i < n; i++){
        cin >> q;
		v.push_back(q);
        freq[q]++;
        soma += q;
		gtr = max(gtr,q);
    }

	for(ll i = 1; i <= gtr; i++){ 
		save[i] = soma+1;
		if(freq[i] == 0){
			save[i] = qt(i-1);
			continue;
		}
		if(freq[i-1] > 0){
			save[i] = min(qt(i-3) + (freq[i-2]*(i-2)) + (freq[i]*(i)),save[i]);
			save[i] = min(qt(i-2) + (freq[i]*(i)),save[i]);
		}
		if(freq[i+1] == 0){
			save[i] = min(qt(i-2) + (freq[i-1]*(i-1)),save[i]);
			save[i] = min(qt(i-1),save[i]);
		}
	}
	cout << soma - save[gtr] << "\n";
 
    return 0;
}