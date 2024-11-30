#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
 
int main(){
 
    int n,m,k; cin >> n >> m;
    set<int> p; map<int,int> qtseq;
    int mseq = n;
    p.insert(0); p.insert(n);
    qtseq[n]++;
 
    for(int i = 0; i < m; i++){
        cin >> k;
        auto nit = p.upper_bound(k);
        auto it = prev(nit);
        p.insert(k);
 
        int oldseq = (*nit) - (*it);
        int n1 = (*nit) - k, n2 = k - (*it);
 
        qtseq[oldseq]--;
        if(qtseq[oldseq] == 0) qtseq.erase(oldseq);
        qtseq[n1]++; qtseq[n2]++;
        
        if(oldseq < mseq){
            cout << mseq << "\n";
        } else {
            mseq = (*qtseq.rbegin()).first;
            cout << mseq << "\n";
        }
    }
 
    return 0;
}