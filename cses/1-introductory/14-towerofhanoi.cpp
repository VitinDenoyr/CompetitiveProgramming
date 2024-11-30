#include <bits/stdc++.h>
using namespace std;
#define ll long long

void move(int m, int a, int b){
	if(m == 1){
		cout << a << " " << b << "\n";
		return;
	}
	move(m-1,a,6-a-b);
	cout << a << " " << b << "\n";
	move(m-1,6-a-b,b);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, k;
	cin >> n;
	k = (1 << n) - 1;
	cout << k << "\n";
	move(n,1,3);

	return 0;
}