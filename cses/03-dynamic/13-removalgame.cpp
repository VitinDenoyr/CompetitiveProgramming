#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5001
#define INF 5000000000001
ll p[MAXN];
vector<ll> qt[2][MAXN];

int main(){

	ll n; cin >> n;
	for(int id = 1; id <= n; id++){
		cin >> p[id];
	}
	for(int s = n; s >= 0; s--){ //Dado que n caras foram escolhidos, calcule pra cada config qual a maior soma
		int ind = s%2;
		for(int i = 0; i <= s; i++){
			int j = s - i;
			if(s == n){
				qt[i%2][j] = {0,0};
			} else {
				if(ind == 0){
					if(qt[(i+1)%2][j][0] + p[i+1] < qt[i%2][j+1][0] + p[n-j]){
						qt[i%2][j] = {qt[i%2][j+1][0] + p[n-j] , qt[i%2][j+1][1]};
					} else {
						qt[i%2][j] = {qt[(i+1)%2][j][0] + p[i+1] , qt[(i+1)%2][j][1]};
					}
				} else {
					if(qt[(i+1)%2][j][1] + p[i+1] < qt[i%2][j+1][1] + p[n-j]){
						qt[i%2][j] = {qt[i%2][j+1][0] , qt[i%2][j+1][1] + p[n-j]};
					} else {
						qt[i%2][j] = {qt[(i+1)%2][j][0] , qt[(i+1)%2][j][1] + p[i+1]};
					}
				}
			}
		}
	}
	cout << qt[0][0][0] << "\n";

	return 0;
}