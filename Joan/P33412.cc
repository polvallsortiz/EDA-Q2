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

int main() {
  vector<double> v(8);
  v[0] = 2;v[1] = 3.2;v[2] = 5;v[3] = 6;v[4] = 8.2;v[5] = 4;v[6] = 9.7;v[7] = 10;
  double abuscar;
  cin >> abuscar;
  if(resistant_search(abuscar,v)) cout << "ESTA" << endl;
  else cout << "NO ESTA" << endl;
}