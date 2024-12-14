#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int FRONT = 0, BACK = 1;
const int INF = 1000000007;

struct Fenwick { //(k', k]
	int len; vector<int> v;
	Fenwick(int n){
		len = n+1; v = vector<int> (len,0);
	}
	void update(int pos, int val){
		while(pos < len){
			v[pos] = min(v[pos],val);
			pos += pos&(-pos);
		}
	}
	int query(int pos){
		int resp = INF;
		while(pos > 0){
			resp = min(v[pos], resp);
			pos -= pos&(-pos);
		}
		return resp;
	}
};

struct FenwickBack { //[k, k')
	int len; vector<int> v;
	FenwickBack(int n){
		len = n+1; v = vector<int> (len,0);
	}
	void update(int pos, int val){
		while(pos > 0){
			v[pos] = min(v[pos],val);
			pos -= pos&(-pos);
		}
	}
	int query(int pos){
		int resp = INF;
		while(pos < len){
			resp = min(v[pos], resp);
			pos += pos&(-pos);
		}
		return resp;
	}
};

int main(){

	

	return 0;
}