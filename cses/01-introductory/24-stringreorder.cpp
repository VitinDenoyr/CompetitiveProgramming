#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int main(){

	vector<int> qt (26, 0);
	string s, r; cin >> s;
	int n = s.length();
	for(char c : s){
		qt[c-'A']++;
		r += " ";
	}

	int prev = -1;
	for(int i = 0; i < n; i++){
		int mx = 0, nx = -1;
		for(int j = 0; j < 26; j++){
			if(qt[j] == 0) continue;
			if(qt[j] > qt[mx]) mx = j;
			if(nx == -1 && prev != j) nx = j;
		}

		if(2*qt[mx] - 1 > (n-i)){
			cout << -1 << "\n";
			return 0;
		}

		if(2*qt[mx] - 1 == (n-i)){
			r[i] = (char)(mx+'A');
			prev = mx;
			qt[mx]--;
		} else {
			r[i] = (char)(nx+'A');
			prev = nx;
			qt[nx]--;
		}
	}
	
	cout << r << "\n";
	return 0;

}