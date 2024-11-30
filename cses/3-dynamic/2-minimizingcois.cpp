#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000100
 
ll qt[MAXN];
ll n, s, k;
vector<ll> v;
 
int main(){
 
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> k;
        v.push_back(k);
    }
    qt[0] = 0;
    for(int i = 1; i <= s; i++){
        qt[i] = MAXN;
        for(ll k : v){
            if(i-k < 0) continue;
            qt[i] = min(qt[i],qt[i-k]+1);
        }
    }
    if(qt[s] >= MAXN) qt[s] = -1;
    cout << qt[s] << "\n";
 
    return 0;
}