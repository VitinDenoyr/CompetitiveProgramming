#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
int qt[MAXN][MAXN]; //Menor número de movimentos transformar r de 0 a x1 em s de 0 a x2
bool ex[MAXN][MAXN]; //Já existe alguma forma de transformar r de 0 a x1 em s de 0 a x2

int main(){
    string r,s;
    cin >> r >> s;
	int l1 = r.length(), l2 = s.length();
	for(int i = 0; i <= l1; i++){
		for(int j = 0; j <= l2; j++){
			//Dado que qt[i][j] já está calculado, temos:
			if(i < l1){
				//Uma forma de transformar r[0...i] em s[0...j-1] é remover o caractere i e depois fazer a mesma coisa que r[0...i-1] em s[0...j-1]. Essa forma é a melhor se for menor que a salva.
				if(ex[i+1][j]){
					qt[i+1][j] = min(qt[i+1][j],qt[i][j]+1);
				} else {
					qt[i+1][j] = qt[i][j]+1;
					ex[i+1][j] = true;
				}
			}
			if(j < l2){
				//Uma forma de transformar r[0...i-1] em s[0...j] é fazer a mesma coisa que r[0...i-1] em s[0...j-1] e depois adicionar o caractere j que falta. Essa forma é a melhor se for menor que a salva.
				if(ex[i][j+1]){
					qt[i][j+1] = min(qt[i][j+1],qt[i][j]+1);
				} else {
					qt[i][j+1] = qt[i][j]+1;
					ex[i][j+1] = true;
				}
			}
			if(i < l1 && j < l2){
				//Podemos ainda transformar r[0...i] em s[0...j] fazendo igual r[0...i-1] em s[0...j-1] e ver se o caractere i e j são o mesmo. Se não forem, basta substituir.
				if(ex[i+1][j+1]){
					qt[i+1][j+1] = min(qt[i+1][j+1],qt[i][j] + (r[i]!=s[j]));
				} else {
					qt[i+1][j+1] = qt[i][j] + (r[i]!=s[j]);
					ex[i+1][j+1] = true;
				}
			}
		}
	}
	//Agora, passamos por todas as situações e então podemos mostrar a resposta final.
	cout << qt[l1][l2] << "\n";
	
	return 0;
}