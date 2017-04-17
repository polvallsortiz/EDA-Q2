//
// Created by Pol Valls Ortiz on 17/4/17.
//
#include <iostream>
#include <vector>
using namespace std;

int fixed_recursive(int a, const vector<int>& v, int left, int right) {
	if(left > right) return -1;
	int middle = (left + right) / 2;
	if((v[middle] + a) < middle) return fixed_recursive(a,v,middle+1,right);
	else if((v[middle] + a) > middle) return fixed_recursive(a,v,left,middle-1);
	else return middle;
}

int first_recursive(int a, const vector<int>& v, int left, int right) {
	if (left >= right) return right;
	int middle = (right + left) / 2;
	if (middle == v[middle] + a) return first_recursive(a, v, left, middle);
	return first_recursive(a, v, middle+1, right);
}


int fixed_point(int a,const vector<int>& v) {
	int aux =  fixed_recursive(a,v,1,v.size()-1);
	if(aux != -1 or aux != 1) {
		return first_recursive(a,v,1,aux);
	}
	else return aux;
}



int main() {
	int n,count = 1;
	while(cin >> n) {
		vector<int> v(n+1);
		for(int i = 1; i <= n; ++i) cin >> v[i];
		cout << "Sequence #" << count << endl;
		int m,aux;
		cin >> m;
		for(int j = 0; j < m; ++j) {
			cin >> aux;
			int aux2 = fixed_point(aux,v);
			if(aux2 == -1) cout << "no fixed point for " << aux << endl;
			else cout << "fixed point for " << aux << ": " << aux2 << endl;
		}
		++count;
		cout << endl;
	}
}
