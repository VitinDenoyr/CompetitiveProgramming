#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define printvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl

int n, q, qtGrads = 0;
int nxt[MAXN][19], posGrad[MAXN], distCyc[MAXN], arriveIn[MAXN], gradNum[MAXN], cycSize[MAXN];
vector<int> ant[MAXN];
bool inCyc[MAXN]; int vis[MAXN];

int conv(int k, int t){
	while(k < 0){
		k += t;
	}
	return k;
}

void backtrackBfs(int a, int n0){
	queue<int> q;
	for(int v : ant[a]){
		q.push(v);
	}
	vis[a] = 2;
	while(!q.empty()){
		int c = q.front(); q.pop();
		distCyc[c] = distCyc[nxt[c][0]] + 1;
		arriveIn[c] = arriveIn[nxt[c][0]];
		gradNum[c] = n0; vis[c] = 2;
		for(int v : ant[c]){
			if(vis[v] != 2){
				q.push(v);
			}
		}
	}
}

void process(int a){
	qtGrads++;

	vis[a] = 1; gradNum[a] = qtGrads;
	while(!vis[nxt[a][0]]){
		a = nxt[a][0];
		vis[a] = 1;
		gradNum[a] = qtGrads;
	}

	a = nxt[a][0];
	inCyc[a] = true; distCyc[a] = 0; posGrad[a] = 1; arriveIn[a] = a;
	while(!inCyc[nxt[a][0]]){
		posGrad[nxt[a][0]] = posGrad[a] + 1;
		a = nxt[a][0];
		inCyc[a] = true;
		distCyc[a] = 0;
		arriveIn[a] = a;
	}
	cycSize[gradNum[a]] = posGrad[a];

	int nd = a;
	for(int p = 1; p <= posGrad[a]; p++){
		nd = nxt[nd][0]; vis[nd] = 2;
		for(int v : ant[nd]){
			if(!inCyc[v]){
				distCyc[v] = 1; arriveIn[v] = nd; gradNum[v] = qtGrads;
				backtrackBfs(v, qtGrads);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> nxt[i][0];
		ant[nxt[i][0]].push_back(i);
	}
	for(int r = 1; r <= 18; r++){
		for(int i = 1; i <= n; i++){
			nxt[i][r] = nxt[nxt[i][r-1]][r-1];
		}
	}

	for(int i = 1; i <= n; i++){
		if(vis[i] == 0){
			process(i);
		}
	}

	for(int i = 1; i <= q; i++){
		int x,y; cin >> x >> y;
		if(gradNum[x] != gradNum[y]){
			cout << "-1\n";
		} else if(x == y){
			cout << "0\n";
		} else if(inCyc[y]){
			cout <<	distCyc[x] + conv(posGrad[y] - posGrad[arriveIn[x]], cycSize[gradNum[x]]) << "\n";
		} else {
			if(distCyc[x] - distCyc[y] > 0){
				int d = distCyc[x] - distCyc[y], sd = d;
				for(int b = 18; b >= 0; b--){
					if((d&(1<<b)) != 0){
						x = nxt[x][b];
						d -= (1<<b);
					}
				}
				if(x == y){
					cout << sd << "\n";
				} else {
					cout << "-1\n";
				}
			} else {
				cout << "-1\n";
			}
		}
	}

	return 0;
}

/*
1) Percorre todos os nós: Se achar um não visitado, entra nele começa a andar e vai indo até repetir, ao achar alguém que repete, vai indo pra frente denovo e marca todos como "no ciclo" da grade e enumera eles em relação ao grade, e com distancia até o ciclo como 0, chegando nele mesmo, guarda tambem o tamanho do ciclo. Depois disso, em cada nó do ciclo, ve se tem alguem vindo para ele de fora do ciclo, se tiver, faz backtrack na arvore e marca todos alcançáveis como na mesma grade e fazendo como BFS, marca a distancia até o ciclo e em qual nó do ciclo ele chega fazendo essa distancia. faz isso até visitar todos os nós. Complexidade: O(N) * constante grande.
3) Pra cada A e B:
	- Se A = B, retorna que sim e a distancia é 0: O(1).
	- Se A e B tiverem em grades diferentes, é impossível chegar um no outro: O(1).
	- Se B estiver no ciclo, é possível chegar até ele: O(1).
		- Pega o nó que A chega até o ciclo, supondo C, e faz |C - B| + distanciaAteOCiclo[A].
	- Se B não estiver no ciclo, só vai ser possivel chegar nele se distanciaAteOCiclo[A] - distanciaAteOCiclo[B] > 0 e ao andar com binary lifting esse valor partindo de A, eu chegar em B: O(LogN).
	
*/