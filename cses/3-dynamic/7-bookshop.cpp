#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1002
#define mod 1000000007
int price[MAXN], pages[MAXN];
int qt[100010]; //Paginas com i dinheiros
 
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
    int n, mcost, mpag = 0, tot = 0; cin >> n >> mcost;
    for(int i = 0; i < n; i++){
        cin >> price[i];
    }
    for(int i = 0; i < n; i++){
        cin >> pages[i];
    }
    qt[0] = 0; //com 0 reais temos 0 páginas
    for(int i = 0; i < n; i++){
        tot = min(tot+price[i],mcost);
        for(int j = tot; j >= price[i]; j--){ //O maior valor a soma dos custos ou o mcost, e o menor escolhendo o livro é price[i], logo:
            qt[j] = max(qt[j - price[i]] + pages[i], qt[j]); //pra cada valor, a qt de paginas vai ser qt[j - preço] + pages[i]
            mpag = max(mpag,qt[j]);
        }
    }
    cout << mpag << "\n";
 
    return 0;
}