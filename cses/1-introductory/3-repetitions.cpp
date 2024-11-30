#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	char c, last = 'N';
	int maxi = 0, curr = 0;
	while(cin >> c){
		if(last == c){
			curr++;
		} else {
			maxi = max(curr,maxi);
			curr = 1;
		}
		last = c;
	}
	cout << max(curr,maxi) << "\n";


	return 0;
}