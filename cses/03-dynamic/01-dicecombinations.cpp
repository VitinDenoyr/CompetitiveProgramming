#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007ll;

vector<ll> save; 

ll soma(ll k){
	if(k < 0) return 0;
	if(save[k] == -1) save[k] = (soma(k-1)+soma(k-2)+soma(k-3)+soma(k-4)+soma(k-5)+soma(k-6))%mod;
	return save[k];
}

int main(){
 
    int n; cin >> n;
	save = vector<ll>(n+1,-1);
	save[0] = 1;
	cout << soma(n) << "\n";
 
    return 0;
}