#include <iostream>
#include <vector>
using namespace std;

bool cerca(const vector<double>&v, int e, int d, double x){
  if (e > d) return false;
  int m = (e + d)/2;
  if (v[m] > x) return ((m + 1 <= d and v[m + 1] == x) or cerca(v, e, m-1, x));
  else if (v[m] < x) return ((m-1 >= e and v[m-1] == x) or cerca (v, m+1, d,x));
  else return true;
}

bool resistant_search(double x, const vector<double>& v){
  return cerca(v, 0, v.size()-1,x);
}