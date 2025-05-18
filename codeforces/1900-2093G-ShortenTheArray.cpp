// https://codeforces.com/problemset/problem/2093/G
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
#define ll long long
#define pii pair<int,int>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = 
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1, 0);
    vector<bool> e1(30, 0), e0(30, 0);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        for(int b = 0; b <= 29; b++){
            if((a[i] & (1 << b)) != 0){
                e1[b] = 1;
            } else {
                e0[b] = 1;
            }
        }
    }
    if(k == 0){
        cout << 1 << "\n";
        return;
    }

    // Handle high bits first
    int bit = 29;
    while((1 << bit) > k){
        if(e1[bit] && e0[bit]){
            cout << 2 << "\n";
            return;
        }
        bit--;
    }

    int resp = n+1;
    // Handle lower bits
    for(int b = bit; b >= 0; b--){
        if((k & (1 << b)) != 0 && b != 0) continue;
        int mask = ((1 << (bit+1)) - 1) - ((1 << b) - 1);
        unordered_map<int, int, custom_hash> ump;
        int kk = (k & mask) + (1 << b);

        for(int i = 1; i <= n; i++){
            if(b == 0 && ump.find((k & mask) ^ (a[i] & mask)) != ump.end()){
                int j = ump[(k & mask) ^ (a[i] & mask)];
                resp = min(i - j + 1, resp);
            }
            if(ump.find(kk ^ (a[i] & mask)) != ump.end()){
                int j = ump[kk ^ (a[i] & mask)];
                resp = min(i - j + 1, resp);
            }
            ump[(a[i] & mask)] = i;
        }
    }

    if(resp == n+1){
        cout << -1 << "\n";
    } else {
        cout << resp << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
