#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
#define pll pair<ll,ll>
 
int main(){
 
    int n,a,b; cin >> n;
    ll r = 0, t = 0;
    vector<pll> p;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        p.push_back({a,b});
    }
    sort(p.begin(),p.end());
    for(int i = 0; i < n; i++){
        t += p[i].first;
        r += p[i].second - t;
    }
    cout << r << "\n";
 
    return 0;
}
