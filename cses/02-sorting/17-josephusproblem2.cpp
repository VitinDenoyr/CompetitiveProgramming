#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;

void solve(){
	vector<vector<int>> v;
	int s = sqrt(n);
	for(int i = 0; i < n; i++){
		if(i%s == 0) v.push_back(vector<int>()); //Início de linha
		v[i/s].push_back(i+1); //Adiciona a criança na linha correspondente
	}

	int L = 0, C = 0;
	for(int m = n; m >= 1; m--){
		int dX = k%m;
		while(C + dX >= v[L].size()){
			dX -= v[L].size(); //Volta as casas correspondentes
			L = (L+1)%(v.size()); //Próxima linha
		}
		C += dX; //Quando chegar aqui, implica que essa linha tem posição C existente
		cout << v[L][C] << " \n"[m == 1]; //Essa foi a criança removida
		v[L].erase(v[L].begin()+C); //Apaga do vetor
		if(C == v[L].size()){ //Ajusta C caso seja a última posição da linha e algum elemento foi apagado
			L = (L+1)%(v.size());
			C = 0;
		}
	}
}

int main() {

	cin >> n >> k;
	solve();

    return 0;

}