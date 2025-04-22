#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	string s; cin >> s;
	s = "0" + s;
	int resp = s.size()-1;
	int qtdif = 0;
	int curr = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] != s[i-1]){
			qtdif++;
		}
		if(s[i] != ('0'+curr)){
			resp++;
			curr = 1 - curr;
		}
	}
	if(qtdif >= 3){
		resp -= 2;
	} else if(qtdif == 2){
		resp--;
	}
	cout << resp << "\n";

}

int32_t main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}