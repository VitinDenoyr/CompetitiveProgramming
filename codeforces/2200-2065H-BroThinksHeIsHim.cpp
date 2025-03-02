//https://codeforces.com/problemset/problem/2065/H
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const ll mod = 998244353ll;
vector<int> p2 (200003, 1);

struct FenwickL {
	int len; vector<ll> v;
	FenwickL(int _n){
		len = _n; v = vector<ll> (len+1, 0);
	}
	void update(int pos, int sign){
		ll val = p2[pos-1] * sign;
		while(pos <= len){
			v[pos] = ((v[pos] + val)%mod + mod)%mod;
			pos += pos&(-pos);
		}
	}
	ll query(int pos){
		ll resp = 0;
		while(pos > 0){
			resp = (resp + v[pos])%mod;
			pos -= pos&(-pos);
		}
		return resp;
	}
};

struct FenwickR {
	int len; vector<ll> v;
	FenwickR(int _n){
		len = _n; v = vector<ll> (len+1, 0);
	}
	void update(int pos, int sign){
		pos = len+1-pos;
		ll val = p2[pos-1] * sign;
		while(pos <= len){
			v[pos] = ((v[pos] + val)%mod + mod)%mod;
			pos += pos&(-pos);
		}
	}
	ll query(int pos){
		pos = len+1-pos;
		ll resp = 0;
		while(pos > 0){
			resp = (resp + v[pos])%mod;
			pos -= pos&(-pos);
		}
		return resp;
	}
};

void solve(){

	string s; cin >> s;
	int n, q; n = s.length();
	s = " " + s;

	//contribX[i] -> Quantas formas podemos escolher caracteres até a posição i de modo que se existir um último, ele seja igual a X
	vector<ll> contrib0 (n+1, 0), contrib1 (n+1, 0);
	contrib0[0] = 1; contrib1[0] = 1;

	for(int i = 1; i <= n; i++){
		if(s[i] == '0'){
			contrib0[i] = (contrib0[i-1] + p2[i-1])%mod;
			contrib1[i] = contrib1[i-1];
		} else {
			contrib0[i] = contrib0[i-1];
			contrib1[i] = (contrib1[i-1] + p2[i-1])%mod;
		}
	}

	//String: Em flX, soma cumulativa dos valores de 2^i para a posição i se o caractere na posição i for X
	FenwickL fl0 (n), fl1 (n);
	FenwickR fr0 (n), fr1 (n);

	//Calcula quantas subsequências são influenciadas por esse caractere i
	ll resp = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] == '0'){
			resp = (resp+(contrib1[i-1] * p2[n-i])%mod)%mod;
			fl0.update(i,1); fr0.update(i,1);
		} else {
			resp = (resp+(contrib0[i-1] * p2[n-i])%mod)%mod;
			fl1.update(i,1); fr1.update(i,1);
		}
	}

	cin >> q;
	for(int j = 1; j <= q; j++){
		int i; cin >> i;
		if(s[i] == '0'){
			//fr0.query(i+1) = How many ways can I make a zero in my right if I'm "i"
			resp = (resp + (fr0.query(i+1) * p2[i-1])%mod + mod)%mod;
			resp = (resp - (fr1.query(i+1) * p2[i-1])%mod + mod)%mod;
			resp = (resp + (fl0.query(i-1) * p2[n-i])%mod + mod)%mod;
			resp = (resp - (fl1.query(i-1) * p2[n-i])%mod + mod)%mod;

			fl0.update(i,-1); fr0.update(i,-1);
			fl1.update(i,1); fr1.update(i,1);
			s[i] = '1';
		} else {
			/*cout << "Minha alteracao eh de 1 -> 0 na posicao " << i << "\n";
			cout << "Vou perder pontos de duas formas:\n";
			cout << "- Sequencias que o primeiro cara a direita é 0 perdem um ponto: total = " << fr0.query(i+1) << "dir x " << p2[i-1] << "esq = " << (fr0.query(i+1) * p2[i-1])%mod << "\n";
			cout << "- Sequencias que o primeiro cara a esquerda é 0 perdem um ponto: total = " << fl0.query(i-1) << "esq x " << p2[n-i] << "dir = " << (fl0.query(i-1) * p2[n-i])%mod << "\n";
			cout << "\n";
			cout << "Vou ganhar pontos de duas formas:\n";
			cout << "- Sequencias que o primeiro cara a direita é 1 ganham um ponto: total = " << fr1.query(i+1) << "dir x " << p2[i-1] << "esq = " << (fr1.query(i+1) * p2[i-1])%mod << "\n";
			cout << "- Sequencias que o primeiro cara a esquerda é 1 ganham um ponto: total = " << fl1.query(i-1) << "dir x " << p2[n-i] << "esq = " << (fl1.query(i-1) * p2[n-i])%mod << "\n";*/
			resp = (resp - (fr0.query(i+1) * p2[i-1])%mod + mod)%mod;
			resp = (resp + (fr1.query(i+1) * p2[i-1])%mod + mod)%mod;
			resp = (resp - (fl0.query(i-1) * p2[n-i])%mod + mod)%mod;
			resp = (resp + (fl1.query(i-1) * p2[n-i])%mod + mod)%mod;

			fl0.update(i,1); fr0.update(i,1);
			fl1.update(i,-1); fr1.update(i,-1);
			s[i] = '0';
		}
		cout << resp << " \n"[j == q];
	}
}

int main(){
	
	ios::sync_with_stdio(false); cin.tie(nullptr);
	for(int i = 1; i <= 200000; i++){
		p2[i] = (2*p2[i-1])%mod;
	}

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}