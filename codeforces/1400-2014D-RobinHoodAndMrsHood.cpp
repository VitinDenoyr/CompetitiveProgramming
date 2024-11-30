//https://codeforces.com/contest/2014/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define INF 10000000

int main(){

	int t; cin >> t;
	while(t--){
		int n,d,k; cin >> n >> d >> k;
		vector<pii> j(n+2,{INF,INF});
		for(int i = 1; i <= k; i++){
			int a,b; cin >> a >> b;
			j[i] = {a,b}; //acaba em b começa em a
		}
		sort(j.begin(),j.end());
		priority_queue<pii,vector<pii>,greater<pii>> jobs; int ji = 0;
		for(int i = 1; i <= d-1; i++){
			while(j[ji].first <= i){
				jobs.push({j[ji].second,j[ji].first});
				ji++;
			}
		}
		pii minv = {n+1,n+1}, maxv = {-100,-100};
		for(int i = 1; i <= n-d+1; i++){
			while(j[ji].first <= i+(d-1)){
				jobs.push({j[ji].second,j[ji].first});
				ji++;
			}
			if((int)(jobs.size()) > (int)(maxv.first)){
				maxv = {jobs.size(),i};
			}
			if((int)jobs.size() < (int)minv.first){
				minv = {jobs.size(),i};
			}
			while(jobs.size() > 0 && jobs.top().first <= i){
				jobs.pop();
			}
		}
		cout << maxv.second << " " << minv.second << "\n";
	}

	return 0;
}