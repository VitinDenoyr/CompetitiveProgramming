#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define INF 1e18
#define pll pair<ll,ll>
ll t[MAXN];
ll calc(ll val, int n){
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += val/t[i];
    }
    return ans;
}
 
int main(){
 
    ll n, p;
    cin >> n >> p;
    ll mi = INF, answ;
    for(int i = 0; i < n; i++){
        cin >> t[i];
        mi = min(mi,t[i]);
    }
    ll l = 1, r = mi*p;
    while(l < r){
        ll mid = (l+r)/2;
        answ = calc(mid,n);
        if(answ < p){
            l = mid+1;
        } else {
            r = mid;
        }
    }
    cout << l << "\n";
 
    return 0;
}
