#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
 
int main(){
 
    int n, k;
    cin >> n >> k;
    int v[n]; ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }
    ll l = sum/k, r = sum;
    while(l < r){
        ll mid = (l+r)/2;
 
        ll qt = 1, ats = 0;
        for(int i = 0; i < n; i++){
            if(ats + v[i] > mid){
                if(v[i] > mid){
                    qt = k+1;
                    break;
                } else {
                    ats = v[i];
                    qt++;
                    if(qt > k) break;
                }
            } else {
                ats += v[i];
            }
        }
 
        if(qt > k){
            l = mid+1;
        } else {
            r = mid;
        }
    }
    cout << l << "\n";
 
 
    return 0;
}