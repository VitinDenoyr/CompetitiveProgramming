#include <bits/stdc++.h>
#include "heap.h"
using namespace std;
#define ll long long
#define pii pair<int,int>

int main(){

	int n;
	cout << "Digite um inteiro N: ";
	cin >> n;

	vector<int> u (n+1, 0); int uMin = (1<<31 - 1), uMax = (1 << 31);
	cout << "Agora, digite N inteiros:\n";
	for(int i = 1; i <= n; i++){
		cin >> u[i];
		uMin = min(uMin, u[i]);
		uMax = max(uMax, u[i]);
	}

	//Algoritmo 1 - Ordenação por Fila (Quesort) - O((uMin - uMax)*N)
	queue<pii> q;
	for(int i = 1; i <= n; i++){
		q.push({u[i],u[i]});
	}
	cout << "Quesort:         [ ";
	while(!q.empty()){
		pii nxt = q.front(); q.pop();
		if(nxt.first == uMin){
			cout << nxt.second << " ";
		} else {
			q.push({nxt.first - 1, nxt.second});
		}
	}
	cout << "]\n";

	//Algoritmo 2 - Ordenação por Contagem (Counting Sort) - O(N + uMax - uMin)
	vector<int> qt (uMax-uMin+1, 0);
	for(int i = 1; i <= n; i++){
		qt[u[i]-uMin]++;
	}
	cout << "Counting Sort:   [ ";
	for(int i = 0; i <= uMax-uMin; i++){
		while(qt[i]){
			cout << i+uMin << " ";
			qt[i]--;
		}
	}
	cout << "]\n";

	//Algoritmo 3 - (Usa comparações) - Implementação do Heap Sort - O(NlogN)
	Heap mh;
	for(int i = 1; i <= n; i++){
		mh.push(u[i]);
	}
	cout << "Heap Sort:       [ ";
	while(!mh.empty()){
		cout << mh.pop() << " ";
	}
	cout << "]\n";

	return 0;
}