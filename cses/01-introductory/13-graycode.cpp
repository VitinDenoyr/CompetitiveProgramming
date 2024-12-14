#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int lastp = 0; //quantas potencias de 2 achamos
int inc(int k){
    bool r = (((((k^(k-1))+1)>>1)^k) == 0);
    lastp += r;
    return r;
}
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    
    int p2n = (1 << n) - 1, reg = 0; //pow(2,n)
    int ver[100000]; //na iteração i foi flipado o bit que ta ak dentro
    bitset<16> bt;
    
    for(int i = 0; i < n; i++){
        cout << bt[i];
    }
    cout << "\n";
    
    for(int i = 1; i <= p2n; i++){
        bool v = inc(i); //se for potencia de 2, flipa um novo bit
        if(v){
            bt[lastp-1].flip();
            ver[i] = lastp-1;
            reg = 0;
        } else { //se não for pow de 2, flipa o cara simetrico a ultima potencia de 2
            bt[ver[i-2*(++reg)]].flip();
            ver[i] = ver[i-2*(reg)];
        }
        for(int i = 0; i < n; i++){
            cout << bt[i];
        }
        cout << "\n";
    }
 
    return 0;
}