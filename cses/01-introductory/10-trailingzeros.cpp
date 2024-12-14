#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
    ll n, div=5, resp = 0;
    cin >> n;
    while(n/div > 0){
        resp += n/div;
        div *= 5;
    }
    cout << resp << "\n";
    
}
