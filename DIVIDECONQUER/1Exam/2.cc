//
// Created by Pol Valls Ortiz on 12/04/2017.
//
#include <iostream>
#include <vector>
using namespace std;

int pos_x(const vector<int>& T, int l, int r, int x) {
	int m = (l+r) / 2;
	if(T[m] < x) return pos_x(T,m,r,x);
	else if(T[m] > x) return pos_x(T,l,m,x);
	else return m;
}

int num_interval(const vector<int>& T, int x, int y) {
	int l = pos_x(T,0,T.size(),x);
	int r = pos_x(T,0,T.size(),y);
	return r - l + 1;
}

int main() {
	vector<int> T(10);
	for(int i = 0; i < 10; ++i) T[i] = i;
	cout << num_interval(T,2,5) << endl;

}
