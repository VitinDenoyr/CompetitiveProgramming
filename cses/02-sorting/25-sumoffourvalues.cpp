#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
#define pii pair<int,int>
 
int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	vector<pii> v;
 
	int n, sm, val; cin >> n >> sm;
	for(int i = 0; i < n; i++){
		cin >> val;
		v.push_back({val,i+1});
	}
	sort(v.begin(),v.end());
	
	for(int j = 0; j < n-3; j++){
		for(int k = j+1; k < n-2; k++){
			int s = sm - v[j].first - v[k].first;
			int r = n-1;
			for(int i = k+1; i < r; i++){
				if(v[i].first + v[r].first == s){
					cout << v[j].second << " " << v[k].second << " " << v[i].second << " " << v[r].second << "\n";
					return 0;
				} else if(v[i].first + v[r].first > s){
					r--; i--;
				}
			}
		}
	}
	cout << "IMPOSSIBLE\n";
 
	return 0;
}
