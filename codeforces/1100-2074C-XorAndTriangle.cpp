#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int x; cin >> x;
	int stage = 0, y = 0;
	for(int i = 0; i <= 30; i++){
		if((1<<i) > x) break;
		if((x&(1<<i)) != 0){
			if((stage & 2) == 0){
				stage += 2;
				y += (1<<i);
			}
		} else {
			if((stage & 1) == 0){
				stage += 1;
				y += (1<<i);
			}
		}
		if(stage == 3){
			if(y > x){
				cout << "-1\n";
			} else {
				cout << y << "\n";
			}
			return;
		}
	}
	cout << "-1\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}