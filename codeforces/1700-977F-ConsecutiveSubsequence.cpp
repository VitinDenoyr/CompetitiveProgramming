//https://codeforces.com/contest/977/problem/F
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
unordered_map<int,int> mseq;

int main(){

	int n; cin >> n;
	vector<int> v;
	for(int i = 1; i <= n; i++){
		int k; cin >> k;
		v.push_back(k);
	}

	pii dp[n] = {{1,0}}; //Tamanho da maior subsequencia que acaba no maximo em i e em quem ela acaba
	mseq[v[0]] = 1;

	for(int i = 1; i < n; i++){
		pii nseq = {mseq[v[i]-1]+1,i};
		mseq[v[i]] = max(nseq.first, mseq[v[i]]);
		if(nseq.first > dp[i-1].first){
			dp[i] = nseq;
		} else {
			dp[i] = dp[i-1];
		}
	}
	cout << dp[n-1].first << "\n";
	int ch = v[dp[n-1].second] - dp[n-1].first + 1;
	for(int i = 0; i < n; i++){
		if(v[i] == ch){
			cout << i+1;
			if(ch == v[dp[n-1].second]){
				cout << "\n";
				break;
			} else {
				cout << " ";
			}
			ch++;
		}
	}
	
	return 0;
}