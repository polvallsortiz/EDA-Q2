#include <iostream>
using namespace std;

double potencia(int x, int n, int mod){
		if (n == 0) return 1;
		else {
				int y = potencia (x, n/2, mod);
				if (n % 2 == 0) return (y*y)%mod;
				else return (((y*y)%mod)*x)%mod;
		}
}

int main (){
		int x, n, mod;
		while(cin >> x >> n >> mod)
		cout << potencia(x, n, mod) << endl;
}
