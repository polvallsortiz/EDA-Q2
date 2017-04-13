#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre){
  int c = (esq+dre)/2;
  if (dre < esq) return -1;
  if (v[c] == x) return c;
  else if (x > v[c]) return posicio (x, v, c + 1, dre);
  else return posicio (x, v, esq, c - 1);
}

