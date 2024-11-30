#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	n *= 2;
	do{
		if(n%2==0){
			n /= 2;
		} else {
			n = n*3 + 1;
		}
		cout << n << " ";
	} while(n != 1);

	return 0;
}