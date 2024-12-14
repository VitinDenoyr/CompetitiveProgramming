#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 10000000
 
bool comp(pair<ll,ll> p1, pair<ll,ll> p2){
    return p1.first < p2.first;
}
 
int main(){
 
    ll n,k;
    cin >> n;
    vector<pair<ll,ll>> v;
    for(ll i = 0; i < n; i++){
        cin >> k;
        v.push_back({k,i+1});
    }
    sort(v.begin(),v.end(),comp);
    //se o i+1 tiver dps do i, economized
    ll ant = INF, resp = n;
    for(ll i = 0; i < n; i++){
        if(v[i].second > ant) resp--;
        ant = v[i].second;
    }
    cout << resp << "\n";
 
    return 0;
}
