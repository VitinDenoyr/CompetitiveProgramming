#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
ll p[20], n, spi = 0;
 
pair<ll,ll> val(int mask, ll* p, ll n0){
    ll rr = 0;
    for(int z = 0; z < n0; z++){
        rr += (((1<<z)&(mask)) > 0) * p[z];
    }
    return {rr,spi-rr};
}
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        spi += p[i];
    }
    
    int lim = 1 << n; ll minv = 1e12;
    
    for(int i = 0; i < lim; i++){
        pair<ll,ll> rn = val(i,p,n);
        minv = min(abs(rn.first - rn.second),minv);
    }
    cout << minv << "\n";
 
    return 0;
}