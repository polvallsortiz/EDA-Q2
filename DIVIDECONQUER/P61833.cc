//
// Created by Pol Valls Ortiz on 17/4/17.
//
#include <iostream>
using namespace std;

struct matrix {
	int M11,M12,M21,M22;
};

/*matrix strassen_alg_pow2(matrix mat, int m) {
	matrix res;
	int P1 = mat.M11 * (mat.M12 - mat.M22);
	int P2 = (mat.M11 + mat.M12) * mat.M22;
	int P3 = (mat.M21 + mat.M22) * mat.M11;
	int P4 = mat.M22 * (mat.M21 - mat.M11);
	int P5 = (mat.M11 + mat.M22) * (mat.M11 + mat.M22);
	int P6 = (mat.M12 - mat.M22) * (mat.M21 + mat.M22);
	int P7 = (mat.M11 - mat.M21) * (mat.M11 + mat.M12);
	res.M11 = (P5 + P4 - P2 + P6) % m;
	res.M12 = (P1 + P2) % m;
	res.M21 = (P3 + P4) % m;
	res.M22 = (P1 + P5 - P3 - P7) % m;
	return res;
}
 */

matrix no_strassen(matrix mat, int m) {
	matrix res;
	res.M11 = (mat.M11 * mat.M11 + mat.M12 * mat.M21) % m;
	res.M12 = (mat.M11 * mat.M12 + mat.M12 * mat.M22) % m;
	res.M21 = (mat.M21 * mat.M11 + mat.M22 * mat.M21) % m;
	res.M22 = (mat.M21 * mat.M12 + mat.M22 * mat.M22) % m;
	return res;
}

matrix power_matrix(matrix mat, int n, int m) {
	matrix res;
	if(n != 0) {
		res = no_strassen(mat, m);
		for (int i = 2; i < n; ++i) res = no_strassen(res, m);
	}
	else {
		res.M11 = 1;
		res.M12 = 0;
		res.M21 = 0;
		res.M22 = 1;
	}
	return res;
}


int main() {
	matrix mat;
	while(cin >> mat.M11 >> mat.M12 >> mat.M21 >> mat.M22) {
		int n,m;
		cin >> n >> m;
		mat = power_matrix(mat,n,m);
		cout << mat.M11 << " " << mat.M12 << endl;
		cout << mat.M21 << " " << mat.M22 << endl;
		cout << "----------" << endl;
	}
}