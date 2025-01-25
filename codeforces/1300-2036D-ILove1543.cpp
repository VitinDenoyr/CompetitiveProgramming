//https://codeforces.com/problemset/problem/2036/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){
	int n,m; cin >> n >> m;
	vector<string> line (n+1, "");
	for(int i = 1; i <= n; i++){
		cin >> line[i];
		line[i] = " " + line[i];
	}
	int resp = 0;
	for(int lay = 0; lay < min(n,m)/2; lay++){
		//cout << ".1\n";
		int state = 0; vector<pii> firsts;
		for(int i = 1+lay; i <= m-1-lay; i++){
			//cout << ".a\n";
			if(line[1 + lay][i] == '1' && state == 0 || line[1 + lay][i] == '5' && state == 1 || line[1 + lay][i] == '4' && state == 2 || line[1 + lay][i] == '3' && state == 3){
				state++;
			} else if(line[1 + lay][i] == '1'){
				state = 1;
			} else {
				state = 0;
			}
			if(state == 4){
				state = 0;
				resp++;
			}
			if(firsts.size() < 3) firsts.push_back({1 + lay,i});
		}
		for(int j = 1 + lay; j <= n-1-lay; j++){
			//cout << ".b\n";
			if(line[j][m - lay] == '1' && state == 0 || line[j][m - lay] == '5' && state == 1 || line[j][m - lay] == '4' && state == 2 || line[j][m - lay] == '3' && state == 3){
				state++;
			} else if(line[j][m - lay] == '1'){
				state = 1;
			} else {
				state = 0;
			}
			if(state == 4){
				state = 0;
				resp++;
				//cout << j << " " << m - lay << "\n";
			}
			if(firsts.size() < 3) firsts.push_back({j,m - lay});
		}
		for(int i = m - lay; i >= 2 + lay; i--){
			//cout << ".c\n";
			if(line[n - lay][i] == '1' && state == 0 || line[n - lay][i] == '5' && state == 1 || line[n - lay][i] == '4' && state == 2 || line[n - lay][i] == '3' && state == 3){
				state++;
			} else if(line[n - lay][i] == '1'){
				state = 1;
			} else {
				state = 0;
			}
			if(state == 4){
				state = 0;
				resp++;
				//cout << n - lay << " " << i << "\n";
			}
			if(firsts.size() < 3) firsts.push_back({n - lay,i});
		}
		for(int j = n - lay; j >= 2 + lay; j--){
			//cout << ".d\n";
			if(line[j][1 + lay] == '1' && state == 0 || line[j][1 + lay] == '5' && state == 1 || line[j][1 + lay] == '4' && state == 2 || line[j][1 + lay] == '3' && state == 3){
				state++;
			} else if(line[j][1 + lay] == '1'){
				state = 1;
			} else {
				state = 0;
			}
			if(state == 4){
				state = 0;
				resp++;
				//cout << j << " " << 1 + lay << "\n";
			}
		}
		if(state == 1 && line[firsts[0].first][firsts[0].second] == '5' && line[firsts[1].first][firsts[1].second] == '4' && line[firsts[2].first][firsts[2].second] == '3'){
			state = 0;
			resp++;
		} else if(state == 2 && line[firsts[0].first][firsts[0].second] == '4' && line[firsts[1].first][firsts[1].second] == '3'){
			state = 0;
			resp++;
		} else if(state == 3 && line[firsts[0].first][firsts[0].second] == '3'){
			state = 0;
			resp++;
		}
	}
	cout << resp << "\n";
}

int main(){

	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}