#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define MAXN 1000005
 
int main(){
    
    int n,k,val,qtdist = 0; cin >> n >> k;
    vector<int> v;
    multiset<pii> s; unordered_map<int,int> qt;
    multiset<pii>::iterator med;
 
    for(int i = 0; i < n; i++){
        cin >> val; v.push_back(val);
        if(i == 0){
            s.insert({val,i}); qt[val]++; qtdist++;
            med = s.begin();
        } else if(i < k){
            s.insert({val,i}); qt[val]++; qtdist++;
            if(val < (*med).first){
                if(qtdist%2 == 0){
                    med = (s.find(*med)); med--;
                }
            } else {
                if(qtdist%2 == 1){
                    med = (s.find(*med)); med++;
                }
            }
        } else {
            s.insert({val,i}); qt[val]++;
 
            qtdist++;
            if(v[i] < (*med).first || (v[i] == (*med).first && i < (*med).second)){
                if(qtdist%2 == 0){
                    med = (s.find(*med)); med--;
                } else {
                    med = (s.find(*med));
                }
            } else {
                //cout << "sou maiorzin\n";
                if(qtdist%2 == 0){
                    med = (s.find(*med));
                } else {
                    med = (s.find(*med)); med++;
                }
            }
            qtdist--;
            if(v[i-k] < (*med).first || (v[i-k] == (*med).first && (i-k) < (*med).second)){
                s.erase({v[i-k],i-k});
                if(qtdist%2 == 1){
                    med = (s.find(*med)); med++;
                } else {
                    med = (s.find(*med));
                }
            } else if(v[i-k] > (*med).first || (i-k) > (*med).second){
                s.erase({v[i-k],i-k});
                if(qtdist%2 == 0){
                    med = (s.find(*med)); med--;
                } else {
                    med = (s.find(*med));
                }
            } else {
                if(qtdist%2 == 0){
                    med = (s.find(*med)); med--;
                } else {
                    med = (s.find(*med)); med++;
                }
                s.erase({v[i-k],i-k});
            }
        }
        med = (s.find(*med));
        if(i >= k-1){
            if(i == n-1){
                cout << (*med).first << "\n";
            } else {
                cout << (*med).first << " ";
            }
        }
    }
 
    return 0;
}