#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    string d; int k = 0;
    do{
        d += s + '\n';
        k++;
    } while(next_permutation(s.begin(),s.end()));
    cout << k << "\n" << d;
 
    return 0;
}