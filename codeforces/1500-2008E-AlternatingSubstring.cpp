//https://codeforces.com/problemset/problem/2008/E
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	int t; cin >> t;
	while(t--){
		int n; string s;
		cin >> n >> s;

		vector<int> qtEven (26,0), qtOdd (26,0);
		vector<int> freqEven (n+1, 0), freqOdd (n+1, 0); freqEven[0] = 26; freqOdd[0] = 26; 

		for(int i = 1; i <= n; i++){
			if(i%2 == 0){
				freqEven[qtEven[s[i-1] - 'a']]--;
				qtEven[s[i-1] - 'a']++;
				freqEven[qtEven[s[i-1] - 'a']]++;
			} else {
				freqOdd[qtOdd[s[i-1] - 'a']]--;
				qtOdd[s[i-1] - 'a']++;
				freqOdd[qtOdd[s[i-1] - 'a']]++;
			}
		}
		int maxEven = 0, maxOdd = 0;
		for(int i = 0; i < 26; i++){
			if(qtEven[i] > maxEven) maxEven = qtEven[i];
			if(qtOdd[i] > maxOdd) maxOdd = qtOdd[i];
		}

		if(n%2 == 0){
			cout << n - maxEven - maxOdd << "\n";
		} else {
			int besty = n;
			for(int i = n; i >= 1; i--){
				if(i%2 == 1){
					freqOdd[qtOdd[s[i-1] - 'a']]--;
					qtOdd[s[i-1] - 'a']--;
					freqOdd[qtOdd[s[i-1] - 'a']]++;
					
					while(freqOdd[maxOdd] == 0) maxOdd--;

					besty = min((n-1) - maxEven - maxOdd + 1, besty);

					freqEven[qtEven[s[i-1] - 'a']]--;
					qtEven[s[i-1] - 'a']++;
					if(qtEven[s[i-1] - 'a'] > maxEven) maxEven = qtEven[s[i-1] - 'a'];
					freqEven[qtEven[s[i-1] - 'a']]++;
				} else {
					freqEven[qtEven[s[i-1] - 'a']]--;
					qtEven[s[i-1] - 'a']--;
					freqEven[qtEven[s[i-1] - 'a']]++;
					
					while(freqEven[maxEven] == 0) maxEven--;

					besty = min(n - maxEven - maxOdd, besty);

					freqOdd[qtOdd[s[i-1] - 'a']]--;
					qtOdd[s[i-1] - 'a']++;
					if(qtOdd[s[i-1] - 'a'] > maxOdd) maxOdd = qtOdd[s[i-1] - 'a'];
					freqOdd[qtOdd[s[i-1] - 'a']]++;
				}
			}
			cout << besty << "\n";
		}
	}

	return 0;
}