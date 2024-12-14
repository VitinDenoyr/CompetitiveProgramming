#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
bool comp(array<int,3> c, array<int,3> d){
    return (c[0] < d[0]);
}
 
int main(){
    
    int n; cin >> n;
    vector<array<int,3>> ev;
    int unavl[n] = {0}, resp = 0;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        ev.push_back({a,i,0});
        ev.push_back({b,i,1});
    }
    sort(ev.begin(),ev.end(),comp);
    int defu = -1;
    for(auto e : ev){
        if(e[2] == 0){
            unavl[e[1]] = e[0];
        } else {
            if(defu <= unavl[e[1]]){
                resp++;
                defu = e[0];
            }
        }
    }
    cout << resp << "\n";
 
    return 0;
}
