#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000100
 
int main(){
    
    ll n; cin >> n;
    vector<ll> s;
    s.push_back(0);
    for(ll i = 0; i < n; i++){
        ll k;
        cin >> k;
        s.push_back(s[i] + k);
    }
    ll minsum = 0, maxsum = -INF, maxdif = -2*INF;
    for(ll i = 1; i <= n; i++){
        maxdif = max(maxdif, s[i] - minsum);
        minsum = min(minsum,s[i]);
    }
    cout << maxdif << "\n";
 
    return 0;
}