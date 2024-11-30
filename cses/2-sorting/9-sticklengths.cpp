#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000001000
 
vector<ll> v;
pair<ll,ll> valuable(ll c){
    ll qtb = 0, qta = 0, qte = 0;
    for(ll el : v){
        qtb += (el < c);
        qta += (el > c);
        qte += (el == c);
    }
    return {(qta-qtb-qte),(qtb-qta-qte)};
}
 
ll dif(ll c){
    ll ans = 0;
    for(ll el : v){
        ans += abs(el-c);
    }
    return ans;
}
 
int main(){
    
    ll n; cin >> n;
 
    ll l = INF, r = -INF;
    for(ll i = 0; i < n; i++){
        ll k;
        cin >> k;
        l = min(l,k);
        r = max(r,k);
        v.push_back(k);
    }
    if(l == r){
        cout << 0 << "\n";
        return 0;
    }
    while(r - l > 1){
        ll mid = (l+r)/2;
        pair<ll,ll> rsp = valuable(mid);
        if(rsp.first > 0){
            l = mid;
        } else if(rsp.second > 0){
            r = mid;
        } else {
            l = mid;
            r = mid;
            break;
        }
    }
    cout << min(dif(l),dif(r)) << "\n";
 
 
    return 0;
}