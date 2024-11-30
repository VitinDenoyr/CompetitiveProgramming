//https://codeforces.com/gym/101021/problem/1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define printvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl

int main(){

	int l = 1, r = 1000000;
	while(l < r){
		int mid = (l+r+1)/2; string resp;
		cout << mid << endl;
		cin >> resp;
		if(resp == "<"){
			r = mid-1;
		} else {
			l = mid;
		}
	}
	cout << "! " << l << endl; 

	return 0;
}