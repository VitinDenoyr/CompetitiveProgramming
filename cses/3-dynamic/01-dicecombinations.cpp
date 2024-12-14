#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
 
int s, val[1000010];
bool mark[1000010];
 
int soma(int v){
    if(mark[v]) return val[v];
    if(v < 1) return 0;
    ll r = 0;
    r = (r + soma(v-6) + soma(v-5) + soma(v-4) + soma(v-3) + soma(v-2) + soma(v-1))%mod;
    mark[v] = true; val[v] = r;
    return val[v];
}
 
int main(){
 
    cin >> s;
    mark[0] = 1; val[0] = 1;
    cout << soma(s) << "\n";
 
    return 0;
}