#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
    ll n, b = 2,ans=1;
    cin >> n;
    while(n > 0){
        if(n%2 == 0){
            b*=b;
            n/=2;
        } else {
            ans*=b;
            if(ans > mod){
                ans %= mod;
            }
            n--;
        }
        if(b > mod){
            b %= mod;
        }
    }
    cout << ans << "\n";
}