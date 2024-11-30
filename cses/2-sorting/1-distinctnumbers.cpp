#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n,k;
	map<int,int> m;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> k;
		m[k]++;
	}
	cout << m.size() << "\n";

	return 0;
}