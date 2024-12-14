//https://codeforces.com/contest/2037/problem/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool question(int l, int r, ll& lastAns){
	cout << "? " << l << " " << r << endl;
	ll prev = lastAns;
	cin >> lastAns;
	return (lastAns != prev);
}

void solve(){
	int n; cin >> n;
	string s = "0";
	string ss = "";
	for(int i = 1; i <= n; i++){
		s += "0"; ss += "0";
	}

	ll l = 1, r = 2, qtZ = 0;
	ll lastAns = 0;
	while(!question(l,r,lastAns)){
		r++;
		if(r == n+1) break;
	}
	if(r == n+1){
		cout << "! IMPOSSIBLE" << endl;
		return;
	}

	//Agora sei que tenho 11111110000000001
	qtZ = lastAns;
	for(int i = r-qtZ-1; i >= 1; i--){ //seta de 1 até r-qtZ-1 como 1, o resto é 0,
		s[i] = '1';
		ss[i-1] = '1';
	}
	s[r] = '1'; //Esse também é 1
	ss[r-1] = '1';

	for(int i = r+1; i <= n; i++){
		bool changed = question(l,i,lastAns);
		if(changed){ //é 1
			s[i] = '1';
			ss[i-1] = '1';
		} else { //se nao, é 0
			qtZ++;
		}
	}
	cout << "! " << ss << endl;
}

int main(){

	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
//01001