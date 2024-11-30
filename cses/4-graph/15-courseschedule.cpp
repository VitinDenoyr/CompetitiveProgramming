#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005

int n,m;
vector<int> adj[MAXN], ord;
int antec[MAXN], rem;

int main(){

	cin >> n >> m;
	rem = n;
	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		antec[b]++;
	}
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(antec[i] == 0) q.push(i);
	}
	while(!q.empty()){
		int nxt = q.front(); q.pop();
		ord.push_back(nxt);
		for(int k : adj[nxt]){
			antec[k]--;
			if(antec[k] == 0) q.push(k);
		}
	}
	if(ord.size() == n){
		for(int e = 0; e < ord.size()-1; e++){
			cout << ord[e] << " ";
		}
		cout << ord[ord.size()-1] << "\n";
	} else {
		cout << "IMPOSSIBLE\n";
	}

	return 0;
}

/*
1) Se A não tem antecessor e X1 X2 ... XJ A Y1 Y2 ... YK é válido, então A X1 ... XJ Y1 ... YK também é válido.
2) Se na ordem valida X1 ... XN, P é o maior número com XP -> XK e Q é o menor número com XK -> XQ, XK pode ir deslizando lado a lado em qualquer lugar e então existe também uma ordem válida com XP e XK vizinhos.  
3) Se em algum momento, escolhermos um termo e ao verificar os seus vizinhos, encontrarmos um termo já visitado, então essa sequência até esse termo não pode ser válida, logo devemos retornar 0 
4) se A é o primeiro e B é um termo que seu antecessor é somente A ou ninguém, então ele pode ser o segundo.
*/