#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int acabInd[MAXN];
 
struct Fenwick{
    vector<int> v; int len; //v[k] -> no intervalo (pai(k),k], qual tamanho da maior subsequencia?
    //Como pai(k) vai recursivamente até 0, podemos perguntar o maior em [0,k]. Nesse problema, 0 será n-1 e n-1 será 0.
    Fenwick(int n){
        len = n+1;
        v = vector<int> (len, 0);
    }
    void update(int ind, int val){
        while(ind < len){
            v[ind] = max(val,v[ind]);
            ind += ind&(-ind);
        }
    }
    int query(int b){
        int resp = v[0];
        while(b > 0){
            resp = max(v[b],resp);
            b -= b&(-b);
        }
        return resp;
    }
};
 
int main(){
 
    int n, vc[MAXN], trueMax = 1;
    vector<int> vec; map<int,int> mask;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> vc[i];
        vec.push_back(vc[i]);
    }
    sort(vec.begin(),vec.end()); //ordena vec para fazer uma máscara para caber na fenwick de 2*10^5
    for(int i = 0; i < n; i++){
        mask[vec[i]] = i+1; //Máscara dos valores
    }
 
    //Agora, resolveremos o problema:
 
    acabInd[0] = 1; //escolhendo só v[0]
    Fenwick ftree(n);
    for(int i = 0; i < n-1; i++){
        ftree.update(mask[vc[i]],acabInd[i]); //Uma subsequência que acaba com índice v[i] tem acabInd[i] elementos
        //Agora, quero saber qual o tamanho da maior sequência que acaba em alguém menor que o próximo termo
        acabInd[i+1] = 1 + ftree.query(mask[vc[i+1]]-1); //Retorna a maior subsequência que acaba em alguém com valor(0,1,2,...,v[i]-1)
        trueMax = max(acabInd[i+1],trueMax);
    }
    ftree.update(mask[vc[n-1]],acabInd[n-1]);
    cout << trueMax << "\n";
 
    return 0;
}