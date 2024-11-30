#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define INF 1000000009
#define pii pair<int,int>
 
int main(){
 
    int n, ent, sai; cin >> n;
    vector<pii> e; vector<int> s;
    for(int i = 0; i < n; i++){
        cin >> ent >> sai;
        e.push_back({ent,i});
        s.push_back(sai);
    }
    sort(e.begin(),e.end());
 
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    int totalRooms = 0, number[n];
    pq.push({INF,MAXN});
    for(int i = 0; i < n; i++){
        if(pq.top().first >= e[i].first){
            totalRooms++;
            pq.push({s[e[i].second],totalRooms});
            number[e[i].second] = totalRooms;
        } else {
            pii topTerm = pq.top();
            number[e[i].second] = topTerm.second;
            pq.pop();
            pq.push({s[e[i].second],topTerm.second});
        }
    }
    cout << totalRooms << "\n";
    for(int i = 0; i < n-1; i++){
        cout << number[i] << " ";
    }
    cout << number[n-1] << "\n";
 
    return 0;
}