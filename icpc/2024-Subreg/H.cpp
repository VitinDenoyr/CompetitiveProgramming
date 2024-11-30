#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	string large, small;
	cin >> large >> small;
	vector<int> aLarge, aSmall;

	//Lê as strings e marca as posições com * em arrays
	for(int i = 0; i < large.length(); i++){
		if(large[i] == '*') aLarge.push_back(i);
	}
	for(int i = 0; i < small.length(); i++){
		if(small[i] == '*') aSmall.push_back(i);
	}

	int max = aLarge.size() + aSmall.size(); //Quantidade de * para testar
	for(int mask = (1<<max)-1; mask >= 0; mask--){ //Combinações de 1's e 0's para colocar nos *
		string big = large, mini = small;
		//Seta os caracteres equivalentes a combinação
		for(int i = 0; i < aLarge.size(); i++){
			big[aLarge[i]] = ('0'+(((1<<i)&(mask)) != 0));
		}
		for(int i = 0; i < aSmall.size(); i++){
			mini[aSmall[i]] = ('0'+(((1<<(i+aLarge.size()))&(mask)) != 0));
		}
		
		//Converte a menor para inteiro
		int conv = 0, powExp = 0;
		for(int i = mini.length()-1; i >= 0; i--){
			if(mini[i] == '1') conv += (1<<powExp);
			powExp++;
		}

		//Calcula para cada bit da maior o resto na divisão pelo inteiro da string menor e soma
		int somaResto = 0, oldp2 = 1;
		for(int i = big.length()-1; i >= 0; i--){
			if(big[i] == '1'){
				somaResto += (oldp2)%conv;
				somaResto %= conv;
			}
			oldp2 = (oldp2*2)%conv;
		}

		//Se a maior tiver resto 0, ela é múltipla, então temos uma resposta
		if(somaResto == 0){
			cout << big << "\n";
			return 0;
		}
	}

	return 0;
}