#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n;
    while(cin >> n){
        ll resp = 0, tm;
        for(tm = 1; (n/tm) - (n/(tm+1)+1) > 0; tm++){ //Então faz a putaria
            ll qt = (n/tm) - (n/(tm+1) + 1)+1;
            ll a0 = n%(n/tm), an = n%(n/(tm+1)+1);
            resp += (a0+an)*qt/2;
        }
        for(ll i = (n/tm); i >= 1; i--){
            resp += n%i;
        }
        ll x1, fac = gcd(n*n,resp), x2;
        x1 = resp/fac, x2 = n*n/fac;
        cout << x1 << "/" << x2 << "\n";
    }
}
