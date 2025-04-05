//https://codeforces.com/contest/2091/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
 
void solve(){
 
	int n; cin >> n;
	vector<int> a (n+1, 0);
	vector<int> qt = {3, 1, 2, 1, 0, 1, 0, 0, 0, 0};
	int qtd = 8; bool ended = false;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(ended) continue;
		if(qt[a[i]] > 0){
			qt[a[i]]--;
			qtd--;
		}
		if(qtd == 0){
			cout << i << "\n";
			ended = true;
		}
	}
	if(ended) return;
	cout << 0 << "\n";
 
}
 
int main(){
 
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}
 
	return 0;
}