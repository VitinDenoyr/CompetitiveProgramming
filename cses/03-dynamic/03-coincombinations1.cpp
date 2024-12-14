#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000010
#define mod 1000000007
 
ll qt[MAXN];
vector<ll> v;
int main(){
    ll n, sum, k;
    cin >> n >> sum;
    for(int i = 0; i < n; i++){
        cin >> k;
        v.push_back(k);
    }
    qt[0] = 1;
    for(int i = 1; i <= sum; i++){
        qt[i] = 0;
        for(auto m : v){
            if(m > i) continue;
            qt[i] += qt[i-m];
            qt[i] %= mod;
        }
    }
    cout << qt[sum] << "\n";
}