//https://codeforces.com/contest/2040/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005

vector<int> save;

void solve(){
	int n; cin >> n;
	cout << save[n] << "\n";
}

int main(){

	int t; cin >> t;
	
	save = vector<int> (2*MAXN+4, 1);
	int qt = 1, ct = 1;
	while(qt <= MAXN){
		ct++;
		int qt2 = 2*(qt+1);
		for(int i = qt+1; i <= qt2; i++){
			save[i] = ct;
		}
		qt = qt2;
	}

	while(t--){
		solve();
	}

	return 0;
}