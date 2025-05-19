#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n,m; cin >> n >> m;
	vector<vector<char>> a (n+1, vector<char> (m+1, 'a'));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if((i+j)%2 == 0){
				if(a[i][j] == 'A'){
					a[i][j] = 'C';
				} else {
					a[i][j] = 'A';
				}
			} else {
				if(a[i][j] == 'B'){
					a[i][j] = 'D';
				} else {
					a[i][j] = 'B';
				}
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << a[i][j];
		}
		cout << "\n";
	}

	return 0;

}