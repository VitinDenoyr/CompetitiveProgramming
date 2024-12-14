#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int ap[9][9];
string s;
int p[48];

int match(int moves, int l, int c){
	if(((ap[l+1][c] && ap[l-1][c]) && (!ap[l][c+1] && !ap[l][c-1])) || ((!ap[l+1][c] && !ap[l-1][c]) && (ap[l][c+1] && ap[l][c-1]))) return 0;

	if(l == 7 && c == 1){
		if(moves == 48) return 1;
		return 0;
	}

	if(moves == 48) return 0;

	int resp = 0; ap[l][c] = 1;
	//cout << moves << "  /  " << l << "," << c << "\t";
	if((s[moves] == '?' || s[moves] == 'L') && !ap[l][c-1]){
		resp += match(moves+1,l,c-1);
	}
	if((s[moves] == '?' || s[moves] == 'R') && !ap[l][c+1]){
		resp += match(moves+1,l,c+1);
	}
	if((s[moves] == '?' || s[moves] == 'U') && !ap[l-1][c]){
		resp += match(moves+1,l-1,c);
	}
	if((s[moves] == '?' || s[moves] == 'D') && !ap[l+1][c]){
		resp += match(moves+1,l+1,c);
	}
	ap[l][c] = 0;
	return resp;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	for(int i = 0; i < 9; i++){
		ap[0][i] = 1; ap[i][0] = 1;
		ap[8][i] = 1; ap[i][8] = 1;
	}

	for(int i = 1; i <= 7; i++){
		for(int j = 1; j <= 7; j++){
			ap[i][j] = 0;
		}
	}

	cin >> s;

	for (int i = 0; i < 48; i++) {
		char cur = s[i];

		if (cur == 'U') p[i] = 0;
		else if (cur == 'R') p[i] = 1;
		else if (cur == 'D') p[i] = 2;
		else if (cur == 'L') p[i] = 3;
		else p[i] = 4;  // cur == '?'
	}

	int ans = match(0,1,1);
	cout << ans << "\n";

	return 0;
}