#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1000000007;

int main(){

	int n,q; cin >> n >> q;
	vector<int> v (n+1, 0);

	//Calcula o tamanho máximo de intervalo necessário para todo inteiro de 1 à N = piso do log
	vector<int> logg (n+1, 0); int currentLog = 0;
	for(int i = 3; i <= n; i++){
		if(((i-1)&(-i+1)) == i-1) currentLog++; //Aumenta após potencias de 2
		logg[i] = currentLog;
	}

	vector<vector<int>> sparse (n+1, vector<int>(currentLog, 0));
	//Leitura do vetor e linha 0 da sparse table
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		sparse[i][0] = v[i];
	}

	//Calcula o restante da sparse table
	for(int i = 1; i <= currentLog; i++){
		for(int j = 1; j <= n; j++){
			if(j + (1<<(i-1)) <= n){
				sparse[j][i] = min(sparse[j+(1<<(i-1))][i-1],sparse[j][i-1]);
			} else {
				sparse[j][i] = sparse[j][i-1];
			}
		}
	}

	for(int iq = 1; iq <= q; iq++){
		int a,b; cin >> a >> b;
		cout << min(sparse[a][logg[b-a+1]], sparse[b - (1<<logg[b-a+1]) + 1][logg[b-a+1]]) << "\n";
	}

	return 0;
}