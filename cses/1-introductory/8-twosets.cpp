#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    ll n;
    cin >> n;
 
    if(n%4 == 1 || n%4 == 2){
        cout << "NO\n";
    } else if(n%4 == 0) {
        cout << "YES\n" << n/2 << "\n";
        for(int i = 1; i <= n/4; i++){
            cout << i << " " << n+1-i << " ";
        }
        cout << "\n" << n/2 << "\n";
        for(int i = 1; i <= n/4; i++){
            cout << n/4 + i << " " << 3*n/4 + 1 - i << " ";
        }
    } else {
        ll k = (n-3)/4;
        cout << "YES\n" << (n-1)/2 << "\n";
        for(int i = 2; i <= 2*k; i += 2){ //k maiores das duplas
            cout << i << " ";
        }
        for(int i = 2*k+3; i <= 4*k+3; i += 2){ //k+1 maiores das duplas
            cout << i << " ";
        }
        cout << "\n" << (n+1)/2 << "\n";
        for(int i = 2; i <= 2*k; i += 2){ //k menores das duplas
            cout << i-1 << " ";
        }
        cout << 2*k+1 << " "; //2k+1
        for(int i = 2*k+3; i <= 4*k+3; i += 2){ //k+1 menores das duplas
            cout << i-1 << " ";
        }
    }
 
    return 0;
}