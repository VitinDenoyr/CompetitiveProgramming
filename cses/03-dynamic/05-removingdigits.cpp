#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000010
int n, qt[MAXN];
 
int main(){
 
    cin >> n;
    qt[0] = 0;
    for(int i = 1; i < 10; i++){
        qt[i] = 1;
    }
    for(int i = 10; i <= n; i++){
        int k = i; qt[i] = MAXN;
        while(k > 0){
            qt[i] = min(qt[i - k%10]+1,qt[i]);
            k /= 10;
        }
    }
    cout << qt[n] << "\n";
 
    return 0;
}