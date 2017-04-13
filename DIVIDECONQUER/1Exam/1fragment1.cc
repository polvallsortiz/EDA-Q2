//
// Created by Pol Valls Ortiz on 12/04/2017.
//
#include <vector>
#include <iostream>
using namespace std;

int lookup1 (vector<int>& T, int x) {
	int l = 0;
	int r = T.size() − 1;
	while (l ≤ r) {
		int m = (l+r) / 2;
		if (x < T[m]) r = m;
		else if (x > T[m]) l = m + 1;
		else return m;
	}
	return −1;
}

int main() {
	vector<int> v(10);
	for(int i = 0; i < 10; ++i) v[i] = i;
	cout << lookup1(v,9) << endl;
}