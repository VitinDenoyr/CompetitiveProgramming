#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, b; vector<int> l;
	ll sum = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> b;
		l.push_back(b);
		sum += b;
	}
	sort(l.begin(),l.end());
	cout << sum + max(l[l.size()-1] - (sum - l[l.size()-1]),(ll)0) << "\n";

	return 0;
}