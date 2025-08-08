//https://codeforces.com/problemset/problem/1903/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	int sx,sy; cin >> sx >> sy;
	vector<vector<int>> point (n+1, vector<int>(3,0));
	set<int> red, black;
	vector<int> isred (n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> point[i][0] >> point[i][1];
		point[i][2] = i;
		if((point[i][0]+point[i][1])%2 == (sx+sy)%2){
			black.insert(point[i][2]);
		} else {
			red.insert(point[i][2]);
			isred[i] = 1;
		}
	}

	if(black.size() >= red.size()){
		cout << "First" << endl;
		//Come pontos vermelhos
		while(red.size() > 0){
			cout << *red.begin() << endl;
			red.erase(red.begin());

			if(red.size() + black.size() > 0){
				int pt; cin >> pt;
				if(isred[pt]){
					red.erase(pt);
				} else {
					black.erase(pt);
				}
			}
		}
		while(black.size() > 0){
			cout << *black.begin() << endl;
			black.erase(black.begin());

			if(black.size() > 0){
				int pt; cin >> pt;
				black.erase(pt);
			}
		}
	} else {
		cout << "Second" << endl;
		//Come pontos pretos
		int pt; cin >> pt;
		if(isred[pt]){
			red.erase(pt);
		} else {
			black.erase(pt);
		}

		while(black.size() > 0){
			cout << *black.begin() << endl;
			black.erase(black.begin());

			if(red.size() + black.size() > 0){
				int pt; cin >> pt;
				if(isred[pt]){
					red.erase(pt);
				} else {
					black.erase(pt);
				}
			}
		}
		while(red.size() > 0){
			cout << *red.begin() << endl;
			red.erase(red.begin());

			if(red.size() > 0){
				int pt; cin >> pt;
				red.erase(pt);
			}
		}
	}
}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}