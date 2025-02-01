#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	int n,q; cin >> n >> q;
	vector<vector<int>> parent (n+1, vector<int>(21, -1));
	for(int i = 2; i <= n; i++){
		cin >> parent[i][0];
	}

	for(int i = 1; i <= 20; i++){
		for(int j = 1; j <= n; j++){
			if(parent[j][i-1] == -1){
				parent[j][i] = -1;
				continue;
			}
			parent[j][i] = parent[parent[j][i-1]][i-1];
		}
	}

	for(int i = 1; i <= q; i++){
		int xi,k; cin >> xi >> k;
		for(int x = 0; (1<<x) <= k; x++){
			if((k&(1<<x)) != 0){
				xi = parent[xi][x];
			}
			if(xi == -1) break;
		}
		cout << xi << "\n";
	}

	return 0;
}