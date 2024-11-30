//https://codeforces.com/gym/105327/problem/H
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	string large, small;
	cin >> large >> small;
	vector<int> aLarge, aSmall;

	for(int i = 0; i < large.length(); i++){
		if(large[i] == '*') aLarge.push_back(i);
	}
	for(int i = 0; i < small.length(); i++){
		if(small[i] == '*') aSmall.push_back(i);
	}

	int max = aLarge.size() + aSmall.size();
	for(int mask = (1<<max)-1; mask >= 0; mask--){
		string big = large, mini = small;
		for(int i = 0; i < aLarge.size(); i++){
			big[aLarge[i]] = ('0'+(((1<<i)&(mask)) != 0));
		}
		for(int i = 0; i < aSmall.size(); i++){
			mini[aSmall[i]] = ('0'+(((1<<(i+aLarge.size()))&(mask)) != 0));
		}
		
		int conv = 0, powExp = 0;
		for(int i = mini.length()-1; i >= 0; i--){
			if(mini[i] == '1') conv += (1<<powExp);
			powExp++;
		}

		int somaResto = 0, oldp2 = 1;
		for(int i = big.length()-1; i >= 0; i--){
			if(big[i] == '1'){
				somaResto += (oldp2)%conv;
				somaResto %= conv;
			}
			oldp2 = (oldp2*2)%conv;
		}

		if(somaResto == 0){
			cout << big << "\n";
			return 0;
		}
	}

	return 0;
}