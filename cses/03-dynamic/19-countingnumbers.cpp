#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll fulldig[20] = {0, 10};
ll prepow[19] = {1,9,81,729,6561,59049,531441,4782969,43046721,387420489,3486784401,31381059609,282429536481,2541865828329,22876792454961,205891132094649,1853020188851841,16677181699666569,150094635296999121};

ll fromZero(ll val){
	if(val == -1){
		return 0;
	}
	ll mpow = 1, exp = 0, resp = 0, valcopy = val;
	while(valcopy >= 10) {
		mpow *= 10;
		exp++;
		valcopy /= 10;  
	}

	resp += fulldig[exp];
	ll ant = 10;
	for(int pos = 1; pos <= exp+1; pos++){ //0 -> primeiro digito, exp -> ultimo
		ll resto = val%mpow; //numero apagando esse digito
		ll dig = (val - resto)/(mpow); //valor do digito
		ll qtCertos = (dig+1) - (pos == 1 && mpow > 1) - (pos < (exp+1)) - (ant <= ((dig-1)+(pos == exp+1))); //Se for o primeiro digito, vc nao pode contar o 0.
		resp += (qtCertos)*(prepow[(exp+1)-pos]);
		if(dig == ant) break;

		val = resto;
		ant = dig;
		mpow /= 10;
	}
	return resp;
}

int main(){

	ll a, b;
	cin >> a >> b;
	for(int i = 2; i <= 18; i++){
		fulldig[i] = fulldig[i-1] + prepow[i];
	}
	cout << (fromZero(b)) - (fromZero(a-1)) << "\n";

	return 0;
}