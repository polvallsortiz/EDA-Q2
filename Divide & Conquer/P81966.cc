//
// Created by Pol Valls Ortiz on 14/03/2017.
//
#include <iostream>
#include <vector>
using namespace std;

int position(double x, const vector<double>& v, int left, int right) {
    int m = (left+right)/2;
    if (left > right) return -1;
    else if (v[m] < x) position(x,v,m+1,right);
    else if (v[m] > x) position(x,v,left,m-1);
    else return m;
}

int main() {

}