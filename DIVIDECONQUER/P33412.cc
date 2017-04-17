//
// Created by Pol Valls Ortiz on 17/4/17.
//
#include <iostream>
#include <vector>
using namespace std;

int pos_search(double x, const vector<double>& v, int left, int right) {
	int middle = (left + right) / 2;
	if(left > right) return -1;
	else {

	}

}

bool resistant_search(double x, const vector<double>& v) {
	if(pos_search(x,v,0,v.size()-1) == -1) return false;
	else return true;
}

int main() {
	vector<double> v(8);
	v[0] = 2;v[1] = 3.2;v[2] = 5;v[3] = 6;v[4] = 4;v[5] = 8.2;v[6] = 9.7;v[7] = 10;
	double abuscar;
	cin >> abuscar;
	if(resistant_search(abuscar,v)) cout << "ESTA" << endl;
	else cout << "NO ESTA" << endl;
}