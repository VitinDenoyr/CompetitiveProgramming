#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<int> a (n, 0);
	map<int,int> qt;
	for(int i = 1; i <= n; i++){
		cin >> a[i-1];
		qt[a[i-1]]++;
	}
	bool forced = false; int last = -1;
	for(pii x : qt){
		if(x.second >= 4){
			cout << "Yes\n";
			return;
		}
		if(x.first - last == 1){
			if(x.second > 1){
				if(forced){
					cout << "Yes\n";
					return;
				} else {
					forced = true;
					last = x.first;
				}
			} else {
				last = x.first;
			}
		} else {
			forced = false;
			last = x.first;
			if(x.second > 1){
				forced = true;
			}
		}
	}
	cout << "No\n";
	return;

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}