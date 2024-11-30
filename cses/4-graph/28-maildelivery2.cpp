#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
 
int n,m;
vector<set<int>> adj;
vector<vector<int>> activate, cycles;
vector<bool> visited;

//Corrigir printagem
int previ = 0, qtdArestas = 0;
std::ostringstream couty;

//Debug
int qtCycUsados = 0;

void follow(int k, int bgn){
	//Como percorrer o ciclo k que foi ativado.
	for(int v = bgn; v < cycles[k].size(); v++){ //no ciclo de posição k, percorre todos os elementos em ordem
		couty << cycles[k][v] << " \n"[qtdArestas == m]; //Cheguei nesse vértice
		qtdArestas++; //Usei uma aresta a mais
		
		while(!activate[cycles[k][v]].empty()){ //Esse vértice ainda ativa algum ciclo. Ativaremos esse ciclo pulando o início dele (que é esse vértice) antes de prosseguir.
			int cycNumber = activate[cycles[k][v]][activate[cycles[k][v]].size() - 1];
			activate[cycles[k][v]].pop_back(); //cout << "(atv " << cycNumber << ")";
			qtCycUsados++; //Usei mais um ciclo
			follow(cycNumber,1);
		} //Após tudo isso, segue normalmente.
	}
}
 
int main(){
	
	//Inicialização
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	adj = vector<set<int>> (n+1, set<int>());
	visited = vector<bool> (n+1, false);
	activate = vector<vector<int>> (n+1, vector<int>());
	

	//Leitura das arestas
	for(int i = 1; i <= m; i++){
		int a,b; cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
 
	//Se qualquer um dos vértices tiver grau par, não existe circuito euleriano
	for(int i = 1; i <= n; i++){
		if(adj[i].size()%2 == 1){
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}

	//Execução do algoritmo. Seja q 
	int q = 0, v = 1;
	visited[1] = true;
	while(q < m){
		//Encontre um vértice v que possua uma aresta não usada
		int it = 0;
		while(adj[v].empty() || visited[v] == false){
			v = (v%n)+1; it++;
			if(it > n){
				cout << "IMPOSSIBLE\n";
				return 0;
			}
		}
		
		//Começaremos um ciclo que tem início nesse vértice
		vector<int> cyc; cyc.push_back(v); visited[v] = true;
		activate[v].push_back(cycles.size()); //O vértice v ativa o ciclo c

		//Tome duas arestas não usadas (v, v1) e (v, last). Nosso ciclo começará indo de v para v1 e acabará indo de last para v. Como usamos as duas, também teremos que removê-las do conjunto de arestas.
		int v1 = *(adj[v].begin()); adj[v].erase(v1); adj[v1].erase(v);
		int last = *(adj[v].begin()); adj[v].erase(last); adj[last].erase(v);
		q += 2; //Como usamos mais duas arestas, aumentamos q em 2.
		cyc.push_back(v1); visited[v1] = true; //Além disso, sabemos que v1 é o próximo vértice em nosso ciclo.
 
		while(adj[v1].size()%2 == 1){ // enquanto a ponta do ciclo tem grau impar, não fechamos o ciclo:
			int v2 = *(adj[v1].begin());
			cyc.push_back(v2); visited[v2] = true; q++; //adiciona o novo vértice no ciclo e conta que usamos mais uma aresta
			adj[v1].erase(v2); adj[v2].erase(v1); //apaga a aresta que escolhi pro ciclo atual
			v1 = v2; //Como não precisamos mais saber da informação do nosso antigo v1, substituimos v1 por o que estava em v2, voltando a uma situação análoga a antes de executar essa iteração do while.
		}

		//Agora, sabemos que v1 = last. Fechamos o ciclo e adicionamos ele à lista de ciclos.
		cyc.push_back(v);
		cycles.push_back(cyc);
	}

	//Sabemos que o primeiro ciclo sempre se inicia com dois vizinhos de 1, se eles não existirem, é impossível sair do quartel principal.
	if(activate[1].size() == 0){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	
	//Seja vx o primeiro dos ciclos que se inicia no quartel principal. Ativamos o ciclo de vx e recursivamente ativam-se todos.
	int vx = activate[1][0];
	activate[1].erase(activate[1].begin());
	follow(vx,0);

	if(qtdArestas == m+1){
		cout << couty.str();
	} else {
		cout << "IMPOSSIBLE\n";
	}
 
	return 0;
}