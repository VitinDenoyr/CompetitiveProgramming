#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
int qt[MAXN][MAXN];

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int a,b;
	cin >> a >> b;
	for(int i = 1; i <= a; i++){
		for(int j = 1; j <= b; j++){
			if(j == i){
				qt[i][j] = 0;
				continue;
			} 
			qt[i][j] = MAXN*MAXN;
			for(int k = 1; k <= i/2; k++){
				qt[i][j] = min(qt[i][j],qt[k][j]+qt[i-k][j]+1);
			}
			for(int k = 1; k <= j/2; k++){
				qt[i][j] = min(qt[i][j],qt[i][k]+qt[i][j-k]+1);
			}
		}
	}
	cout << qt[a][b] << "\n";

	return 0;
}