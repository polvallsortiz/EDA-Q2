#include <iostream>
#include <vector>
using namespace std;

int fixedpoint (int a, const vector <int>& v, int i, int f){
	if (f < i) return -1;
	int m = (f+i)/2;
	if (m == v[m]+a) return m;
	else if(m > v[m]+a){
		return fixedpoint(a, v, m + 1, f);
	}
	return fixedpoint(a, v, i, m - 1);
}

int checkfi (int a, const vector <int>& v, int i, int f){
	if (i >= f) return f;
	int m = (f+i)/2;
	if (m == v[m]+a) return checkfi(a, v, i, m);
	return checkfi(a, v, m+1, f);
	 	
}

int firstfixedpoint(int a, const vector <int>& v, int i, int f){
	int fi = fixedpoint(a, v, 1, v.size()-1);
	if (fi == -1) return -1;
	else return checkfi(a, v, 1, fi);
}
	
int main(){
		int s;
		int n = 0;
		while (cin >> s){
			++n;
			cout <<"Sequence #" <<n << endl;
			vector <int> v (s+1);
			for (int i = 1; i <= s; ++i){
				cin >> v[i];
			}
			int c;
			cin >> c;
			int a;
			for (int j = 0; j < c; ++j){
				cin >> a;
				int t = firstfixedpoint(a, v, 1, v.size()-1);
				if (t == -1) cout << "no fixed point for " << a << endl;
				else cout << "fixed point for " << a <<": " << t << endl;
				
			}
		cout << endl;
		}
}
