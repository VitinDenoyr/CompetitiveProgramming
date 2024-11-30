#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int tab[10][10];
	map<char,int> conv; 
	conv['T'] = 2; conv['B'] = 3; conv['R'] = 4; conv['W'] = 5; conv['P'] = 6;
	while(cin >> n){
		memset(tab,0,sizeof(tab));
        //1 = solo, 2 = torre, 3 = bispo, 4 = rainha, 5 = rei, 6 = peão, 7 = livre, 8 = inexistente
		for(int i = 0; i < 10; i++){ //Seta bordas como "não existe": o rei não pode ir nelas
			for(int j = 0; j < 10; j++){
				if(i == 0 || j == 0 || i == 9 || j == 9){
					tab[i][j] = 8;
				} else {
					tab[i][j] = 7;
				}
			}
		}
		string king, piece;
		for(int i = 0; i < n; i++){
			cin >> piece;
			tab[piece[2]-'0'][piece[1]-'a'+1] = conv[piece[0]];
			//cout << piece[2] << "," << (int)(piece[1]-'a'+1) << " to " << conv[piece[0]] << " = " << tab[piece[2]][(int)(piece[1]-'a'+1)] << "\n";
		}
		cin >> king;
		int kingl = king[2]-'0', kingc = king[1]-'a'+1;
		tab[kingl][kingc] = 1;
		for(int l = 1; l <= 8; l++){
			for(int c = 1; c <= 8; c++){
				if(abs(tab[l][c]) > 1 && abs(tab[l][c]) < 7){ //Processa o ataque dessa peça
					if(abs(tab[l][c]) == 2) { //Torre
						int save = tab[l][c];
						for(int lin = 1; lin <= 8; lin++){
							tab[lin][c] = -1*abs(tab[lin][c]);
							if(abs(tab[lin][c]) <= 6) break;
						}
						for(int col = 1; col <= 8; col++){
							tab[l][col] = -1*abs(tab[l][col]);
							if(abs(tab[l][col]) <= 6) break;
						}
						tab[l][c] = save;
					} else if(abs(tab[l][c]) == 3) { //Bispo
						int save = tab[l][c];
						int lin = l, col = c;
						while(lin >= 2 && col >= 2){ //cima esq
							lin--; col--;
							tab[lin][col] = -1*abs(tab[lin][col]);
							if(abs(tab[lin][col]) <= 6) break;
						}
						lin = l, col = c;
						while(lin >= 2 && col <= 7){ //cima dir
							lin--; col++;
							tab[lin][col] = -1*abs(tab[lin][col]);
							if(abs(tab[lin][col]) <= 6) break;
						}
						lin = l, col = c;
						while(lin <= 7 && col >= 2){ //baixo esq
							lin++; col--;
							tab[lin][col] = -1*abs(tab[lin][col]);
							if(abs(tab[lin][col]) <= 6) break;
						}
						lin = l, col = c;
						while(lin <= 7 && col <= 7){ //baixo dir
							lin++; col++;
							tab[lin][col] = -1*abs(tab[lin][col]);
							if(abs(tab[lin][col]) <= 6) break;
						}
						tab[l][c] = save;
					} else if(abs(tab[l][c]) == 4) { //Rainha
						int save = tab[l][c];
						for(int lin = 1; lin <= 8; lin++){
							tab[lin][c] = -1*abs(tab[lin][c]);
							if(abs(tab[lin][c]) <= 6) break;
						}
						for(int col = 1; col <= 8; col++){
							tab[l][col] = -1*abs(tab[l][col]);
							if(abs(tab[l][col]) <= 6) break;
						}
						int lin = l, col = c;
						while(lin >= 2 && col >= 2){ //cima esq
							lin--; col--;
							tab[lin][col] = -1*abs(tab[lin][col]);
							if(abs(tab[lin][col]) <= 6) break;
						}
						lin = l, col = c;
						while(lin >= 2 && col <= 7){ //cima dir
							lin--; col++;
							tab[lin][col] = -1*abs(tab[lin][col]);
							if(abs(tab[lin][col]) <= 6) break;
						}
						lin = l, col = c;
						while(lin <= 7 && col >= 2){ //baixo esq
							lin++; col--;
							tab[lin][col] = -1*abs(tab[lin][col]);
							if(abs(tab[lin][col]) <= 6) break;
						}
						lin = l, col = c;
						while(lin <= 7 && col <= 7){ //baixo dir
							lin++; col++;
							tab[lin][col] = -1*abs(tab[lin][col]);
							if(abs(tab[lin][col]) <= 6) break;
						}
						tab[l][c] = save;
					} else if(abs(tab[l][c]) == 5) { //Rei inimigo
						tab[l+1][c+1] = -1*abs(tab[l+1][c+1]);
						tab[l+1][c-1] = -1*abs(tab[l+1][c-1]);
						tab[l+1][c] = -1*abs(tab[l+1][c+1]);
						tab[l-1][c-1] = -1*abs(tab[l+1][c-1]);
						tab[l-1][c+1] = -1*abs(tab[l+1][c+1]);
						tab[l-1][c] = -1*abs(tab[l+1][c-1]);
						tab[l][c+1] = -1*abs(tab[l+1][c+1]);
						tab[l][c-1] = -1*abs(tab[l+1][c-1]);
					} else if(abs(tab[l][c]) == 6) { //Peão
						tab[l-1][c+1] = -1*abs(tab[l-1][c+1]);
						tab[l-1][c-1] = -1*abs(tab[l-1][c-1]);
					}
				}
			}
		}
		string resp = "SIM";
		for(int li = kingl-1; li <= kingl+1; li++){
			for(int co = kingc-1; co <= kingc+1; co++){
				if(tab[li][co] >= 0 && abs(tab[li][co]) != 8){
					resp = "NAO";
					break;
				}
			}
		}
		cout << resp << "\n";
	}

	return 0;
}