#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int m[26] = {0};
 
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        m[s[i]-'A']++;
    }
 
    string front = "", mid = "", back = "";
    for(int i = 0; i < 26; i++){
        if(m[i] == 0) continue;
        front = front + string(m[i]/2, (char)(i+'A'));
        back = string(m[i]/2, (char)(i+'A')) + back;
        if(m[i]%2 == 1){
            mid += (char)(i+'A'); 
            if(mid.length() > 1) break;
        }
    }
 
    if(mid.length() > 1){
        cout << "NO SOLUTION\n";
    } else {
        cout << (front + mid + back) << "\n";
    }
 
    return 0;
}