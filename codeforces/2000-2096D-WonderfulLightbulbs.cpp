#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	map<int,int> qtX, qtXY;
	for(int i = 1; i <= n; i++){
		int a,b; cin >> a >> b;
		qtX[a]++; qtXY[b+a]++;
	}

	int x,y;
	for(pii k : qtX){
		if(k.second%2){
			x = k.first;
			break;
		}
	}
	for(pii k : qtXY){
		if(k.second%2){
			y = k.first - x;
			break;
		}
	}
	cout << x << " " << y << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}