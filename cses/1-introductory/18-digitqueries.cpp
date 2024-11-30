#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll q, v, dig[18] = {0}; //dig[i] -> quantos caracteres usados até ter todos os números de i dígitos
	cin >> q;
	for(int i = 1; i <= 17; i++){
		dig[i] = dig[i-1] + (ll)9*(ll)pow(10,i-1)*(ll)i;
		//cout << dig[i] << " " << i << "\n";
	}
	for(int i = 0; i < q; i++){
		cin >> v;
		ll ult, qtd;
		for(int j = 0; j < 17; j++){
			if(dig[j+1] >= v){ //Com j dígitos, não temos v caracteres, mas com j+1 sim.
			//Logo, a resposta é um dígito de um número de j+1 dígitos.
			//Como dig[17] > 10^18, sempre é suficiente em algum momento.
				qtd = j+1;
				ult = dig[j];
				break;
			}
		}
		//cout << qtd << " " << ult << " " << v << "\n";
		ll intcorr = pow(10,qtd-1); //Esse é o primeiro número a ser escrito: v = 170 , qtd = 2, ult = 9, intcorr = 10
		ll qtnumsmult = ((v-ult) + qtd*((v-ult)%qtd>0) - (v-ult)%qtd), qtnums = qtnumsmult/qtd; //floor(161/2) = 80 números
		int volta = (qtnumsmult) - (v-ult);
		intcorr += qtnums-1;
		//cout << intcorr << "   " << volta << "   ";
		for(int z = 0; z < volta; z++){
			intcorr = (intcorr-intcorr%10)/10;
		}
		intcorr %= 10;
		cout << intcorr << "\n";
	}
	cout << fixed << setprecision(0) << (ll)158888888888888857/pow(10,0);

	return 0;
}
