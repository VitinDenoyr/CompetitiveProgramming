//https://codeforces.com/problemset/problem/2053/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<int> l (n+1, 0), r (n+1, 0);
	vector<int> cl (2*n+2, 0), wcl (2*n+2, 0);

	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
		if(l[i] == r[i]){
			cl[l[i]] = 1;
			wcl[l[i]]++;
		}
	}

	for(int i = 2*n; i >= 1; i--){
		cl[i] += (cl[i] > 0)*(cl[i+1]);
	}

	for(int i = 1; i <= n; i++){
		if(l[i] == r[i]){
			if(wcl[l[i]] == 1){
				cout << 1;
				continue;
			}
			cout << 0;
			continue;
		}
		bool skip = false;
		for(int j = l[i]; j <= r[i]; j++){
			if(cl[j]){
				j += cl[j]-1;
				continue;
			}
			cout << 1; skip = true;
			break;
		}
		if(skip) continue;
		cout << 0;
	}
	cout << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}