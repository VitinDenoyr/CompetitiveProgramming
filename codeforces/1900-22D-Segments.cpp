//https://codeforces.com/problemset/problem/22/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<int> v (n+1, 0);
	vector<vector<int>> evs;
	int kr = 0;
	for(int i = 1; i <= n; i++){
		int a,b; cin >> a >> b;
		if(a >= b) swap(a,b);
		evs.push_back({a,0,i});
		evs.push_back({b,1,i});
	}
	vector<int> picked;
	sort(evs.begin(),evs.end());
	vector<int> pos;

	for(int i = 0; i < evs.size(); i++){
		if(evs[i][1] == 0){
			picked.push_back(evs[i][2]);
		} else {
			if(v[evs[i][2]] == 1) continue;
			for(int x : picked){
				v[x] = 1;
			}
			picked.clear();
			kr++;
			pos.push_back(evs[i][0]);
		}
	}

	cout << kr << "\n";
	for(int ip = 0; ip < pos.size(); ip++){
		cout << pos[ip] << " \n"[ip==(pos.size()-1)];
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	solve();
	return 0;

}