//https://codeforces.com/problemset/problem/2036/G
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll ask(ll a, ll b, ll& x){
	cout << "xor " << a << " " << b << endl;
	cin >> x;
	return x;
}

void answer(ll a, ll b, ll c){
	cout << "ans " << a << " " << b << " " << c << endl;
}

vector<ll> subprob(ll l, ll r, ll totalXor, ll mostNums){
	if(l > r || l <= 0) return {};
	if((l == r) && totalXor != 0){
		return {totalXor};
	} else if(mostNums == 1 && totalXor != 0){
		return {totalXor};
	}

	ll mid = (l+r)/2ll, resp;
	ask(l,mid,resp);

	if((l == r) && resp != 0){
		return {resp};
	} else if(mostNums == 1 && resp != 0){
		return {resp};
	} else if(resp == totalXor){ //Nesse intervalo não perdemos ninguém
		return subprob(l,mid,totalXor,mostNums);
	} else if(resp == 0){ //Nesse intervalo, não tem mais nada
		return subprob(mid+1,r,totalXor,mostNums);
	} else {
		vector<ll> r1 = subprob(l,mid,resp,max(mostNums-1,1ll));
		vector<ll> r2 = subprob(mid+1,r,totalXor^resp,max(mostNums-1,1ll));
		for(ll z : r2) r1.push_back(z);
		return r1;
	}
}

void solve(){
	ll n; cin >> n;
	if(n == 3){ answer(1,2,3); return; }
	ll resp; ask(1,n,resp); //Recebo o xor total.

	if(resp == 0){
		ll gp2 = 0; while((1ll<<(gp2+1)) <= n) gp2++; //gp2 -> maior potencia de 2 que cabe em n
		while(ask(1,(1ll<<gp2),resp) == 0) gp2--; //Se ele gasta k operações aqui
		vector<ll> r1 = subprob(1,(1ll<<gp2),resp,2); //log2(2^d) -> ele gasta 60-k operações aqui
		vector<ll> r2 = subprob((1ll<<gp2)+1,n,resp,3 - r1.size()); //log2(n - 2^d) -> e tecnicamente gasta 60 aqui, ent deveria ser dboa
		for(ll z : r2) r1.push_back(z);
		answer(r1[0],r1[1],r1[2]);
	} else {
		vector<ll> r1 = subprob(1,n,resp,3);
		answer(r1[0],r1[1],r1[2]);
	}
}

int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

//FIXME: Código extremamente buxa lento ruim paia7


/*
1010100101111011
1101001101011111
0010101010100100

*/