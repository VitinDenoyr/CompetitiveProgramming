#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
 
int main(){
    
    int n, s; cin >> n >> s;
    vector<pii> v;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        v.push_back({k,i}); 
    }
    sort(v.begin(),v.end());
    bool couted = false;
    for(int i = 0; i < n-1; i++){
        int l = i+1, r = n-1, obj = s - v[i].first;
        while(l < r){
            int mid = (l+r)/2;
            if(v[mid].first > obj){
                r = mid-1;
            } else if(v[mid].first < obj){
                l = mid+1;
            } else {
                l = mid; r = mid;
            }
        }
        if(obj == v[l].first){
            cout << v[i].second+1 << " " << v[l].second+1 << "\n";
            couted = true;
            break;
        }
    }
    if(!couted){
        cout << "IMPOSSIBLE\n";
    }
 
    return 0;
}
