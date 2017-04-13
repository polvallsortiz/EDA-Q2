#include <iostream>
#include <vector>
using namespace std;


vector <vector <int> > powermat(vector <vector <int> > M, int n, int m){
  if (n == 0){
    M[0][0] = M[1][1] = 1;
    M[0][1] = M[1][0] = 0;
    return M;
  }else {
      vector <vector <int> > M2 = powermat(M, n/2, m);

      vector <vector <int> > M3 (2, vector<int> (2));
      for(int i = 0; i < 2; ++i){
        for (int j = 0; j < 2; ++j){
          int x = 0;
          for (int k = 0; k < 2; ++k){
            x += M2[i][k] * M2[k][j];
          }
          M3[i][j] = x%m;
        }
      }

      if (n % 2 == 0)return M3;
      else {
        vector <vector <int> > M4 (2, vector<int> (2));
        for(int l = 0; l < 2; ++l){
          for (int j = 0; j < 2; ++j){
            int x = 0;
            for (int k = 0; k < 2; ++k){
              x += M3[l][k] * M[k][j];
            }
            M4[l][j] = x%m;
          }
        }
        return M4;
      }
  }
}

void writemat(vector <vector <int> > M){
  cout << M[0][0] << " " << M[0][1] << endl << M[1][0] << " " << M[1][1] << endl << "----------" << endl;
}

int main(){
  vector <vector <int> > M (2, vector<int> (2));
  int n, m;
  while(cin >> M[0][0] >> M[0][1] >> M[1][0] >> M[1][1]){
    cin >> n >> m;
    writemat(powermat(M, n, m));
  }
}
