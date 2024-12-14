#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vs vector<string>
#define vb vector<bool>

//Rdiag -> i-j+7, Ldiag -> i+j, [0,14]

int test(vs& v, int line, vb& cols, vb& rdiag, vb& ldiag, int& qt){
	if(line == 8) return qt++;
	for(int c = 0; c < 8; c++){ //Testa se pode uma rainha em [line, c]
		if(v[line][c] == '.' && !cols[c] && !rdiag[line-c+7] && !ldiag[line+c]){
			cols[c] = 1; rdiag[line-c+7] = 1; ldiag[line+c] = 1;
			test(v,line+1,cols,rdiag,ldiag,qt);
			cols[c] = 0; rdiag[line-c+7] = 0; ldiag[line+c] = 0;
		}
	}
	return qt;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string s; vector<string> v;
	for(int i = 0; i < 8; i++){
		cin >> s;
		v.push_back(s);
	}
	vector<bool> cols0 (8, false), rdiag0 (15, false), ldiag0 (15, false);
	int qt = 0;
	test(v, 0, cols0, rdiag0, ldiag0, qt);
	cout << qt << "\n";

	return 0;
}