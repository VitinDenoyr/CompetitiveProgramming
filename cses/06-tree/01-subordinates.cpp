#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<int> subords, parent;
vector<vector<int>> sons;

void calcSub(int k){
	for(int s : sons[k]){
		calcSub(s);
		subords[k] += subords[s] + 1;
	}
}

int main(){

	int n; cin >> n;
	parent = vector<int>(n+1, 0); subords = vector<int>(n+1, 0);
	sons = vector<vector<int>> (n+1, vector<int>());
	for(int i = 2; i <= n; i++){
		cin >> parent[i];
		sons[parent[i]].push_back(i);
	}
	calcSub(1);
	for(int i = 1; i <= n; i++){
		cout << subords[i] << " \n"[i == n];
	}

	return 0;
}