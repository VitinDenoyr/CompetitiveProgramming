//https://codeforces.com/gym/105327/problem/H
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	string l, s; cin >> l >> s;
	vector<int> indL, indS;
	for(int i = 0; i < l.size(); i++){
		if(l[i] == '*') indL.push_back(i);
	}
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '*') indS.push_back(i);
	}

	for(int x = 0; x < (1<<indL.size()); x++){
		for(int y = 0; y < (1<<indS.size()); y++){

			ll num = 0; int sI = 0, lI = 0;
			for(int i = s.size()-1; i >= 0; i--){
				int j = s.size()-i-1;
				if(s[i] == '*'){
					num += (1<<j)*((y&(1<<sI++)) != 0);
				} else {
					num += (1<<j)*(s[i] == '1');
				}
			}

			ll rem = 0;

			ll value = 1;
			for(int i = l.size()-1; i >= 0; i--){
				if(l[i] == '1' || (l[i] == '*' && (x&(1<<lI++)))){
					rem += value;
				}
				value = (value * 2)%num;
				rem %= num;
			}
			
			if(rem%num == 0){
				int lli = 0;
				for(int i = l.size()-1; i >= 0; i--){
					if(l[i] == '*'){
						l[i] = (char)('0' + ((x&(1<<lli++)) != 0));
					}
				}
				cout << l << "\n";
				return 0;
			}
		}
	}

	return 0;
}