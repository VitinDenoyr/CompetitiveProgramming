#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n,k; cin >> n >> k;
	vector<int> moves, state (n+1, 0); 
	for(int i = 1; i <= k; i++){
		int p; cin >> p;
		moves.push_back(p);
	}
	state[0] = 2; //Perde
	function<bool(int)> calc = [&](int x) -> bool{
		if(state[x] != 0) return (state[x] == 1);
		bool tr = true;
		for(int m : moves){
			if(x-m >= 0){
				tr &= calc(x-m);
			}
		}
		state[x] = 2 - !tr;
		return (state[x] == 1);
	};
	calc(n);

	stringstream s;
	for(int i = 1; i <= n; i++){
		s << (state[i] == 2 ? "L" : "W");
	}
	cout << s.str() << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	solve();
	return 0;

}