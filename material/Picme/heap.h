#pragma once
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

class Heap {
private:
	vector<int> v; bool t;
	void maintainPush(int id){
		int p = id/2;
		if(p == 0) return;
		if(v[p] > v[id]){
			swap(v[p],v[id]);
			maintainPush(p);
		}
	}
	void maintainPop(int id){
		int s1 = 2*id;
		int s2 = 2*id+1;
		if(s1 >= v.size()) return; //Sem filhos, árvore correta
		if(s2 >= v.size() && v[s1] < v[id]){ //Só um filho, basta corrigir ele
			swap(v[s1],v[id]);
			return;
		}
		if(v[s1] > v[s2]) swap(s1,s2); //Garante s1 índice do menor
		if(v[s1] < v[id]){
			swap(v[s1],v[id]);
			maintainPop(s1);
		}
	}
public:
	Heap(bool isMaxHeap = false){
		t = 1-isMaxHeap;
		v.push_back((int)((1ll<<31)-1ll)); //Pivô representando tamanho máximo que cabe na pilha
	}
	void push(int x){
		v.push_back(x*(2*t - 1));
		maintainPush(v.size()-1);
	}
	bool empty(){
		return (v.size() == 1);
	}
	int top(){
		if(empty()){
			throw std::out_of_range("Requiring top element on an empty heap");
		}
		return v[1]*(2*t - 1);
	}
	int intMax(){
		return v[0];
	}
	int pop(){
		if(empty()){
			throw std::out_of_range("Popping from an empty heap");
		}
		int peakElement = v[1];
		v[1] = v[v.size()-1];
		v.pop_back();
		maintainPop(1);
		return peakElement*(2*t - 1);
	}
};