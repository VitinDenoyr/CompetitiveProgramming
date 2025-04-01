#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void order5elements(vector<int> v = {}){
	if(v.size() < 5){
		v.clear();
		cout << "Digite os 5 elementos: ";
		for(int i = 0; i < 5; i++){
			int j; cin >> j; v.push_back(j);
		}
	}
	cout << "Array: [" << v[0] << "," << v[1] << "," << v[2] << "," << v[3] << "," << v[4] << "]\n";

	if(v[0] > v[1]) swap(v[0],v[1]); //Comparação 1
	if(v[2] > v[3]) swap(v[2],v[3]); //Comparação 2
	if(v[0] > v[2]){ //Comparação 3
		swap(v[0],v[2]);
		swap(v[1],v[3]);
	}

	vector<int> arr = {v[0], v[2], v[3]};
	if(v[4] > v[2]){ //Comparação 4
		if(v[4] > v[3]){ //Comparação 5
			arr.push_back(v[4]);
		} else {
			arr.push_back(v[3]);
			arr[2] = v[4];
		}
	} else {
		if(v[4] < v[0]){ //Comparação 5
			arr.push_back(v[3]);
			arr[2] = v[2];
			arr[1] = v[0];
			arr[0] = v[4];
		} else {
			arr.push_back(v[3]);
			arr[2] = v[2];
			arr[1] = v[4];
		}
	}
	
	if(v[1] < arr[2]){ //Comparação 6
		if(v[1] < arr[1]){ //Comparação 7
			cout << "Seus elementos em ordem sao: [" << arr[0] << "," << v[1] << "," << arr[1] << "," << arr[2] << "," << arr[3] << "]\n";
		} else {
			cout << "Seus elementos em ordem sao: [" << arr[0] << "," << arr[1] << "," << v[1] << "," << arr[2] << "," << arr[3] << "]\n";
		}
	} else {
		if(v[1] < arr[3]){ //Comparação 7
			cout << "Seus elementos em ordem sao: [" << arr[0] << "," << arr[1] << "," << arr[2] << "," << v[1] << "," << arr[3] << "]\n";
		} else {
			cout << "Seus elementos em ordem sao: [" << arr[0] << "," << arr[1] << "," << arr[2] << "," << arr[3] << "," << v[1] << "]\n";
		}
	}
}

int main(){

	vector<int> p = {1,2,3,4,5};
	for(int i = 1; i <= 120; i++){
		order5elements(p);
		next_permutation(p.begin(),p.end());
	}

	return 0;

}