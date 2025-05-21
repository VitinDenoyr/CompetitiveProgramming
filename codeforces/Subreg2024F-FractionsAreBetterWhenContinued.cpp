//https://codeforces.com/gym/105327/problem/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int mdc(int a,int b){
	if(a == 0) return b;
	return mdc(b%a, a);
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	int a = 1, b = 1;
	for(int i = 1; i <= n; i++){
		a += b;
		swap(a,b);
	}
	int m = mdc(a,b);
	cout << a << "\n";

}