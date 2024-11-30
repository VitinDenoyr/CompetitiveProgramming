#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
    ll n, m, t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        if(m > n){
            if((m - (m-n)*2)%3 == 0 && m <= 2*n){
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            if((n - (n-m)*2)%3 == 0 && n <= 2*m){
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    
    return 0;
}