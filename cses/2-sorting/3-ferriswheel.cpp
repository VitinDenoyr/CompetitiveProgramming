#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll n, maxw, cr;
	vector<int> c;
	cin >> n >> maxw;
	for(int i = 0; i < n; i++){
		cin >> cr;
		c.push_back(cr);
	}
	sort(c.begin(),c.end());
	int mark[n] = {0};
	int i = 0, j = n-1, r = 0;
	while(i < j){
		if(c[i] + c[j] <= maxw){
			mark[i] = 1; mark[j] = 1;
			i++; j--; r++;
		} else {
			mark[j] = 1;
			j--; r++;
		}
	}
	if(!mark[i]) r++;
	cout << r << "\n";

	return 0;
}