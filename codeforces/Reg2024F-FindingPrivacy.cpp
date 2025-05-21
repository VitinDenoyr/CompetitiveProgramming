//https://codeforces.com/gym/105505/problem/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n,k; cin >> k >> n;
	if(n >= 2*k-1 && n <= 3*k){
		int qtres = n - (2*k - 1);
		vector<string> ans (k, "X-");
		ans[k-1] = "X";
		for(int i = 0; (qtres > 0 && i < k); i++){
			ans[i] = "-" + ans[i];
			qtres--;
		}
		if(qtres > 0){
			ans[k-1] = "-X-";
		}
		for(int i = 0; i < k; i++){
			cout << ans[i];
		}
		cout << "\n";

	} else {
		cout << "*\n";
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	solve();
	return 0;

}