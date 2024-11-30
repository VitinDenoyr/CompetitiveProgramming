#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
 
int main(){
    
    vector<ll> v;
    ll n, k, val; cin >> n >> k;
    for(ll i = 0; i < n; i++){
        cin >> val;
        v.push_back(val);
    }
 
    map<ll,ll> qt;
    ll l = 0, r = 0, distinct = 1, total = 0; qt[v[0]]++;
    while(r < n){
        if(distinct <= k){
            total++; r++;
            if(r < n && qt[v[r]]++ == 0){
                distinct++;
            } else if(r == n){
                //Não é um subconjunto válido pois nem é subconjunto, e ninguém mais vai ser.
                distinct = k+1;
            }
            //Contei que [l,r] vale, e agora só vou verificar [l,r+1]. Como r só aumenta, perdi todo mundo que acaba em r, contido {[l+1,r], ... , [r,r]}
            total += r-1-l; //Há r-l conjuntos em {[l+1,r], ... , [r,r]} e todos valem, mas meu r vale r+1
        } else { //Pegando esse intervalo, significa que não é um subconjunto válido
            if(qt[v[l++]]-- == 1){ //Se não sobrar cópias do elemento l que acabou de avançar, então tem 1 distinct a menos
                distinct--;
            }
            //Contei que [l,r] não vale, então vou verificar [l+1,r]. Como l só aumenta, perdi apenas pessoas que já foram contadas então não importa
        }
    }
    cout << total << "\n";
 
    return 0;
}