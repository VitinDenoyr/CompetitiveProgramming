#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

struct triple {
	int t, a, b;
	triple(int _a, int _b, int _t) :t(_t), a(_a), b(_b){}
};

bool comp(triple x, triple y){
	if(x.a < y.a) return true;
	if(x.a > y.a) return false;
	return x.b > y.b;
}

int n;
vector<triple> range;

//Fenwick tree que responde queries "quantos arrays tem final menor que X"
struct Fenwick {
	int len, tot; vector<int> v;
	Fenwick(int _n){
		len = _n+1; tot = 0;
		v = vector<int> (len, 0);
	}
	//Adiciona um intervalo [l,r] nos considerados, mas só precisamos saber de r
	void update(int r){
		tot++;
		while(r < len){
			v[r]++;
			r += r&(-r);
		}
	}
	//Pergunta quantos intervalos tem final menor ou igual a r
	int query(int r){
		int resp = 0;
		while(r > 0){
			resp += v[r];
			r -= r&(-r);
		}
		return resp;
	}
};

int main(){

	cin >> n;
	range = vector<triple> (n+1, triple(0,0,0));
	map<int,int> conv; vector<int> vals; int qt = 0;
	for(int i = 1; i <= n; i++){
		int a,b; cin >> a >> b;
		range[i] = {a,b,i};
		vals.push_back(a); vals.push_back(b);
	}

	//Faz a compressão de coordenadas para facilitar a fenwick tree
	sort(vals.begin(),vals.end());
	for(int k : vals) conv[k] = ++qt;
	for(int i = 1; i <= n; i++){
		range[i] = triple(conv[range[i].a],conv[range[i].b],range[i].t);
	}

	//Ordena os intervalos por ordem de início e secundariamnete por ordem de final, ambos de forma crescente
	sort(range.begin(),range.end(),comp);
	vector<int> inAns (n+1, 0), outAns (n+1, 0);
	Fenwick f(qt), g(qt);

	//Para cada intervalo, faz uma query entre os intervalos que começam depois dele em quantos terminam antes dele
	for(int i = n; i >= 1; i--){
		inAns[range[i].t] = f.query(range[i].b);
		f.update(range[i].b);
	}

	//Para cada intervalo, faz uma query entre os intervalos que começam antes dele quantos terminam depois
	for(int i = 1; i <= n; i++){
		outAns[range[i].t] = g.tot - g.query(range[i].b-1);
		g.update(range[i].b);
	}

	for(int i = 1; i <= n; i++) cout << inAns[i] << " \n"[i == n];
	for(int i = 1; i <= n; i++) cout << outAns[i] << " \n"[i == n];

	return 0;
}