#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1002
#define mod 1000000007
char tab[MAXN][MAXN];
int qt[MAXN][MAXN];
 
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
    int n; cin >> n;
    for(int i = 0; i <= n+1; i++){
        tab[i][0] = '*';
        tab[0][i] = '*';
        tab[n+1][i] = '*';
        tab[i][n+1] = '*';
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> tab[i][j];
        }
    }
    qt[1][1] = 1;
    if(tab[1][1] == '*'){
        cout << 0 << "\n";
        return 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(tab[i][j] == '*') continue;
            if(tab[i-1][j] == '.'){
                qt[i][j] += qt[i-1][j];
            }
            if(tab[i][j-1] == '.'){
                qt[i][j] += qt[i][j-1];
            }
            qt[i][j] %= mod;
        }
    }
    cout << qt[n][n] << "\n";
 
    return 0;
}