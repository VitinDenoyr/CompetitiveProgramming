#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int,int>> ev; //first -> hora, second -> tipo (0 = entra, 1 = sai)
	for(int i = 0; i < n; i++){
		int a,b;
		cin >> a >> b;
		ev.push_back({a,0});
		ev.push_back({b,1});
	}
	sort(ev.begin(),ev.end());
	int m = 0, c = 0;
	for(int i = 0; i < ev.size(); i++){
		if(ev[i].second == 0){
			c++;
			m = max(c,m);
		} else {
			c--;
		}
	}
	cout << m << "\n";

	return 0;
}