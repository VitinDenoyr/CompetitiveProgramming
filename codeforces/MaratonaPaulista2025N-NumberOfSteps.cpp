//https://codeforces.com/gym/105904/problem/N
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;

	vector<vector<int>> div (1000100, vector<int>());
	vector<int> isPrime (1000100, 1);
	vector<int> qt (1000100, 0), state (1000100, 0), freq (1000100, 0);
	freq[0] = 1000000;

	for(int i = 2; i <= 1000000; i++){
		if(isPrime[i] == 1){
			div[i].push_back(i);
			for(int j = 2*i; j <= 1000000; j += i){
				isPrime[j] = 0;
				div[j].push_back(i);
			}
		}
	}

	int mx = 0;
	for(int i = 1; i <= n; i++){
		int di; cin >> di;
		if(state[di] == 0){
			for(int u : div[di]){
				freq[qt[u]]--;
				freq[qt[u]+1]++;
				qt[u]++;
				mx = max(mx,qt[u]);
			}
		} else {
			for(int u : div[di]){
				freq[qt[u]]--;
				freq[qt[u]-1]++;
				qt[u]--;
			}
		}
		state[di] = 1 - state[di];
		while(freq[mx] == 0){
			mx--;
		}
		cout << mx << "\n";
	}
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	solve();
	return 0;

}