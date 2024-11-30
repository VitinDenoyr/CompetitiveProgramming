#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
 
ll v[MAXN], resp[MAXN], qtresp[MAXN];
 
struct Fenwick {
    vector<ll> bit; ll len;
    Fenwick(ll n){
        len = n;
        bit = vector<ll> (len, 0);
    }
    void update(ll ind, ll qt){
        while(ind < len){
            bit[ind] += qt;
            ind += ind&(-ind);
        }
    }
    ll query(ll a){
        ll r = 0;
        while(a > 0){
            r += bit[a];
            a -= a&(-a);
        }
        return r;
    }
};
 
ll cost(ll target, ll x, ll y){
    ll an = 0;
    for(ll z = x; z <= y; z++){
        an += abs(target - v[z]);
    }
    return an;
}
 
int main(){
    
    ll n,k;
    cin >> n >> k;
 
    unordered_map<ll,ll> p, rev;
    set<ll> s;
 
    for(ll i = 0; i < n; i++){
        cin >> v[i];
        s.insert(v[i]);
    }
 
    ll id = 1;
    for(auto k : s){
        rev[id] = k;
        p[k] = id++;
    }
 
    Fenwick ftree(id);
 
    for(ll i = 0; i < n; i++){
        if(i < k){
            ftree.update(p[v[i]],1);
        } else {
            ftree.update(p[v[i]],1);
            ftree.update(p[v[i-k]],-1);
        }
        if(i >= k-1){
            ll l = 1, r = id-1, qtMen, qtMai, qtIg;
            while(l < r){
                ll mid = (l+r)/2;
                ll ans = ftree.query(mid);
                if(ans >= (k+1)/2){
                    r = mid;
                } else {
                    l = mid+1;
                }
            }
            
            if(i == k-1){
                resp[i] = rev[l]; qtresp[i] = cost(rev[l],i-k+1,i);
            } else {
                resp[i] = rev[l];
                ll stateN = (v[i] > rev[l]) - (v[i] < rev[l]), stateP = (v[i-k] > rev[l]) - (v[i-k] < rev[l]);
                if(stateN == stateP){
                    qtresp[i] = qtresp[i-1] + (v[i] - v[i-k])*(stateN);
                } else {
                    if(v[i-k] < resp[i-1]){
                        qtMen--;
                    } else if(v[i-k] > resp[i-1]){
                        qtMai--;
                    } else {
                        qtIg--;
                    }
                    qtresp[i] = qtresp[i-1] + (qtMen - qtMai)*(rev[l] - resp[i-1]) + qtIg*abs(rev[l] - resp[i-1]) - abs(resp[i-1] - v[i-k]) + abs(rev[l] - v[i]);
                }
            }
            
            qtMen = ftree.query(l-1);
            qtIg = ftree.query(l) - qtMen;
            qtMai = k - qtIg - qtMen;
            cout << qtresp[i];
            if(i < n-1){
                cout << " ";
            } else {
                cout << "\n";
            }
        }
    }
    return 0;
}