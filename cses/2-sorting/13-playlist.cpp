#include <bits/stdc++.h>
using namespace std;
#define INF 10000000
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
    int n; cin >> n;
    int m[n];
    for(int i = 0; i < n; i++){
        cin >> m[i];
    }
    int st = 0, ml = 0;
    map<int,int> mp;
    for(int i = 0; i < n; i++){
        mp[m[i]]++;
        if(mp[m[i]] > 1){
            while(mp[m[i]] > 1){
                mp[m[st]]--;
                st++;
            }
        } else {
            ml = max(ml,i-st+1);
        }
        //cout << "[" << st << "," << i << "]\n";
    }
    cout << ml << "\n";
    
 
    return 0;
}