//https://codeforces.com/contest/2085/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n; //[4, 5000]
	vector<int> a (n+1, 0); //pos de 0 à n
	vector<int> qt (n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		qt[a[i]]++;
	}
	vector<pii> ops;
	if(a[1] == 0){
		ops.push_back({1,2});
		qt[a[1]]--;
		qt[a[2]]--;
		if(qt[0] > 0){
			ops.push_back({2,n-1});
			ops.push_back({1,2});
		} else {
			ops.push_back({1,n-1});
		}
	} else {
		if(qt[0] > 0){
			ops.push_back({2,n});
			ops.push_back({1,2});
		} else {
			ops.push_back({1,n});
		}
	}

	cout << ops.size() << "\n";
	for(pii p : ops){
		cout << p.first << " " << p.second << "\n";
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}