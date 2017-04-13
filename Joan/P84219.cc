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

int posicio2(double x, const vector<double>& v, int esq, int dre){
  if (esq >= dre) return dre; 
  int c = (esq+dre)/2;
  if (v[c] == x) return posicio2 (x, v, esq, c); 
  return posicio2 (x, v, c + 1, dre);
}

int first_occurrence(double x, const vector<double>& v){
		int p = posicio(x, v, 0, v.size()-1);
		if (p == -1) return -1;
		else return posicio2(x, v, 0, p);
}

int main(){
		double n;
		cin >> n;
		vector<double> v;
		double d;
		while (cin >> d) v.push_back(d);
		cout << first_occurrence(n, v) << endl;
}
