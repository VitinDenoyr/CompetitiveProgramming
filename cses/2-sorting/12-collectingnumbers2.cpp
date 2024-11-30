#include <bits/stdc++.h>
using namespace std;
#define ll int
#define INF 10000000
 
bool comp(pair<ll,ll> p1, pair<ll,ll> p2){
    return p1.first < p2.first;
}
 
int main(){
 
    ll n,m,k;
    cin >> n >> m;
    vector<pair<ll,ll>> v;
    vector<int> pos;
    pos.push_back(n+1);
    v.push_back({0,INF});
    v.push_back({n+1,-INF});
    for(ll i = 1; i <= n; i++){
        cin >> k;
        pos.push_back(k);
        v.push_back({k,i});
    }
    pos.push_back(0);
    sort(v.begin(),v.end(),comp);
    ll resp = n, maiorq[n+2] = {0};
    for(ll i = 1; i <= n+1; i++){
        if(v[i].second > v[i-1].second){
            resp--;
            maiorq[i] = 1;
        }
    }
    //Resp guarda a quantidade que dava antes
 
    for(ll j = 0; j < m; j++){ //Pra cada query:
        int a,b;
        cin >> a >> b;
        int pa = pos[a], pb = pos[b]; //números que estão nessas posições. no caso, os pa-ésimo e pb-ésimo caras no v.
        //estão em v[pa] e v[pb]. Seus valores serão trocados e as posições em pos tbm
        ll aux = v[pa].second, p_aux = pos[a];
        v[pa].second = v[pb].second; pos[a] = pos[b];
        v[pb].second = aux; pos[b] = p_aux;
 
        // agora calcularemos que diferença isso dá
        //Resp soma o antigo e subtrai o atual: atual - antigo
        resp -= (v[pa].second > v[pa-1].second) - (maiorq[pa]);
        maiorq[pa] = (v[pa].second > v[pa-1].second);
        if(pa+1 != pb){
            resp -= (v[pa+1].second > v[pa].second) - (maiorq[pa+1]);
            maiorq[pa+1] = (v[pa+1].second > v[pa].second);
        }
        
        resp -= (v[pb].second > v[pb-1].second) - (maiorq[pb]);
        maiorq[pb] = (v[pb].second > v[pb-1].second);
        if(pb+1 != pa){
            resp -= (v[pb+1].second > v[pb].second) - (maiorq[pb+1]);
            maiorq[pb+1] = (v[pb+1].second > v[pb].second);
        }
        
        cout << resp << "\n";
    }
 
    return 0;
}