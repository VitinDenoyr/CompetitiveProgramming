#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n,k; cin >> n >> k;
	k -= (n-1);
	cout << (k / n) << "\n";

}