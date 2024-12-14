#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define MAXM 102
#define MAXN 100003
int v[MAXN];
int qt[MAXN][MAXM];
 
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    int mah = m, meh = 1;
    for(int i = 1; i <= n; i++){
        if(v[i] == 0){
            meh = max(meh-1,1), mah = min(mah+1,m);
            if(i == 1){
                for(int j = meh; j <= mah; j++){
                    qt[i][j] = 1;
                }
            } else {
                for(int j = meh; j <= mah; j++){
                    qt[i][j] = ((qt[i-1][j] + qt[i-1][j+1])%mod + qt[i-1][j-1])%mod;
                }
            }
        } else {
            if(i == 1){
                qt[i][v[i]] = 1;
                mah = v[i], meh = v[i];
                continue;
            }
            qt[i][v[i]] = ((qt[i-1][v[i]] + qt[i-1][v[i]+1])%mod + qt[i-1][v[i]-1])%mod;
            mah = v[i], meh = v[i];
        }
    }
 
    int s = 0;
    for(int i = 1; i <= m; i++){
        s += qt[n][i];
        s %= mod;
    }
    cout << s << "\n";  
 
    return 0;
}