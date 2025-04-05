//https://codeforces.com/contest/1996/problem/G
#include <bits/stdc++.h>
#include <time.h>
#include <random>
#include <chrono>
using namespace std;
#define ll long long
#define MAXM 200005
#define pii pair<int,int>

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); //random integer 64 bits
int main(){

	int t; cin >> t;
	while(t--){
		int n,m; cin >> n >> m; //Considere um N-agono regular e um conjunto de M "arestas/diagonais" que vão ser dadas no enunciado
		vector<vector<int>> pert (n, vector<int>()); //pert[i] -> todas as arestas que o vertice i pertence
		unordered_map<ll,int> mp;
		vector<ll> conv (m);
		for(int i = 0; i < m; i++){
			int a,b;
			cin >> a >> b; //aresta a <-> b
			a--; b--;
			pert[a].push_back(i); //vertice a tem aresta i
			pert[b].push_back(i); //vertice b tem aresta i
			conv[i] = rng();
		}
		int msz = 0; ll id = 0;
		for(int i = 0; i < n; i++){ //lado de i -> i+1 
			ll zeta = ++mp[id]; //esse lado do polígono está nessa configuração de lados na diagonal
			if(msz < zeta) msz = zeta; //o maior numero de lados que estão no mesmo lado em todas as arestas é msz
			for(int ares : pert[(i+1)%n]){
				id ^= conv[ares]; //mudei de lado nessa diagonal ao atravessar o vertice i+1
			}
		}
		cout << n - msz << "\n"; //ignora isso, só saiba que eu so preciso saber msz => maior numero de lados do poligono que estao do mesmo lado em todas as arestas dadas
	}
	
	return 0;
}

