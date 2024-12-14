#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, k; cin >> n;

	vector<int> v;
	cin >> k; v.push_back(k);

	for(int i = 1; i < n; i++){
		cin >> k;
		if(k >= v[v.size()-1]){
			v.push_back(k);
		} else {
			int l = 0, r = v.size()-1;
			while(l < r){
				int md = (l+r)/2;
				if(v[md] <= k){
					l = md+1;
				} else {
					r = md;
				}
			}
			v[l] = k;	
		}
	}
	cout << v.size() << "\n";

	return 0;
}