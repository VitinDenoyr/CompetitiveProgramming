//https://codeforces.com/gym/105327/problem/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

bool verify(vector<vector<int>> a, int n){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < n; j++){
			if(a[i][j] > a[i][j+1]) return false;
			if(a[j][i] > a[j+1][i]) return false;
		}
	}
	return true;
}

vector<vector<int>> rotate(vector<vector<int>> a, int n){
	vector<vector<int>> b (n+1, vector<int> (n+1, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			b[i][j] = a[j][n-i+1];
		}
	}
	return b;
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	
	vector<vector<int>> a (n+1, vector<int> (n+1, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}

	for(int i = 0; i < 4; i++){
		if(verify(a,n)){
			cout << i << "\n";
		}
		a = rotate(a,n);
	}

	return 0;

}