//https://codeforces.com/contest/2055/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	int n; cin >> n;
	vector<int> a (n+1, 0), mat (n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	int state = 0, dif = 0, id = 0;
	for(int i = 1; i <= n; i++){
		cin >> mat[i];
		if(mat[i] > a[i]){
			state++; //ta faltando
			dif = mat[i]-a[i];
			id = i;
		}
	}

	if(state >= 2){
		cout << "NO\n";
		return;
	} else if(state == 0){
		cout << "YES\n";
		return;	
	}

	for(int i = 1; i <= n; i++){
		if(i != id){
			a[i] -= dif;
		} else {
			a[i] += dif;
		}
		if(mat[i] > a[i]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	return;	
}

int main(){

	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}