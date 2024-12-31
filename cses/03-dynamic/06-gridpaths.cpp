#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007ll;

vector<vector<ll>> tab, qt;

int main(){

    int n; cin >> n;
	tab = vector<vector<ll>>(n+2, vector<ll>(n+2,0));
	qt = vector<vector<ll>>(n+2, vector<ll>(n+2,0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c; cin >> c;
			if(c == '.') tab[i][j] = 1;
        }
    }

    qt[1][1] = tab[1][1]; tab[1][1] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!tab[i][j]) continue;
            qt[i][j] = (qt[i][j-1] + qt[i-1][j])%mod;
        }
    }
    cout << qt[n][n] << "\n";
 
    return 0;
}