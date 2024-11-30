#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define INF 10000000000000000
 
int main(){
    
    ll n,a,b; cin >> n >> a >> b;
    vector<ll> s;
    s.push_back(0);
    for(ll i = 0; i < n; i++){
        ll k;
        cin >> k;
        s.push_back(s[i] + k);
    }
    ll maxdif = -2*INF;
    priority_queue<pll,vector<pll>,greater<pll>> minsum;
    minsum.push({0,0});
    for(ll i = a; i <= n; i++){
        while(minsum.top().second < i-b){
            minsum.pop();
        }
        maxdif = max(maxdif, s[i]-minsum.top().first);
        minsum.push({s[i-a+1],i-a+1});
    }
    cout << maxdif << "\n";
 
    return 0;
}