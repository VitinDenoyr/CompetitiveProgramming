//https://codeforces.com/problemset/problem/1999/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int main(){

	int t; cin >> t;
	for(int it = 0; it < t; it++){
		int n,s,m, a,b; vector<pii> task;
		cin >> n >> s >> m;
		for(int i = 0; i < n; i++){
			cin >> a >> b;
			task.push_back({a,b});
		}
		sort(task.begin(),task.end());
		int fml = 0; bool ans = false;
		for(int i = 0; i < n; i++){
			if(task[i].first - fml >= s){
				ans = true;
				break;
			}
			fml = task[i].second;
		}
		if(m - fml >= s || ans){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}