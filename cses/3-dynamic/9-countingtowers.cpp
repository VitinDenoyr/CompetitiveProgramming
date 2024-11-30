#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define MAXN 1000010
ll qt[MAXN] = {0}; //qt[i] -> quantas formas posso montar um bloco 2xi.
ll qtl[MAXN] = {0}; //qtl[i] -> quantas formas posso montar um bloco 2xi sem grudar a primeira fileira

ll salvo = 0;
ll countTo(ll p, ll q, bool lim){ //2,2,0
	if(qt[p] > 0 && p == q){
		if(lim) return qtl[p];
		return qt[p];
	}
	ll mini = min(p,q), resp; //Minimo e Resp
	if(lim == 0){
		if(p == q){
			ll prevSum = countTo(p-1,p-1,0) - countTo(p-1,p-1,1);
			resp = (countTo(p,p,1) + countTo(p-1,p-1,0)) + prevSum;
			while(resp >= mod) resp -= mod;
			while(resp < 0) resp += mod;
			qt[p] = resp;
			salvo++;
		} else {
			resp = (countTo(mini,mini,0)+countTo(mini,mini,1));
			while(resp >= mod) resp -= mod;
			while(resp < 0) resp += mod;
		}
	} else {
		resp = (2*countTo(p-1,q,0) - countTo(p-1,p-1,0) + countTo(p-1,p-1,1));
		while(resp >= mod) resp -= mod;
		while(resp < 0) resp += mod;
		qtl[p] = resp;
		salvo++;
	}

	return resp;
}

int main(){

	int t; ll n;
	cin >> t;
	qt[0] = 1; qtl[0] = 1;
	qt[1] = 2; qtl[1] = 1;
	for(int ti = 0; ti < t; ti++){
		cin >> n;
		cout << countTo(n,n,0) << "\n";
	}

	return 0;
}