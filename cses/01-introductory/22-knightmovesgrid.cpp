#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1000000000;

int main(){

	int n; cin >> n;
	vector<vector<int>> g (n+1, vector<int> (n+1, INF));

	queue<vector<int>> q;
	q.push({1,1,0}); g[1][1] = 0;
	while(!q.empty()){
		int x = q.front()[0],y = q.front()[1],v = q.front()[2]; q.pop();
		vector<int> mL = {2,2,-2,-2,1,1,-1,-1};
		vector<int> mR = {1,-1,1,-1,2,-2,2,-2};

		for(int i = 0; i < 8; i++){
			int xi = x + mL[i], yi = y + mR[i];
			if(xi <= n && xi >= 1 && yi <= n && yi >= 1){
				if(g[xi][yi] == INF){
					g[xi][yi] = v+1;
					q.push({xi,yi,v+1});
				}
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << g[i][j] << " \n"[j==n];
		}
	}

	return 0;

}