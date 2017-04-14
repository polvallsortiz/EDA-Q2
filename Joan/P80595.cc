#include <iostream>
#include <vector>
using namespace std;

int inv(vector<int>& v, int l, int m, int r){
  vector <int> b(r-l+1);
  int i = l, j = m + 1, k = 0;
  int in = 0;
  int dretes = 0;
  while (i <= m and j <= r){
    if (v[i] <= v[j]){
      b[k++] = v [i++];
      in += dretes;
    }
    else{
      b[k++] = v[j++];
      ++dretes;
    }
  }
  while (i <= m) {
    b[k++] = v[i++];
    in += dretes;
  }
  while (j <= r) {
    b[k++] = v[j++];
    ++dretes;
  }
  for(k = 0; k <= r-l; ++k) v[l + k] = b[k];
  return in;
}

int mergesort(vector <int>& v, int l, int r){
  if (l < r){
    int m = (l + r)/2;
    int x = mergesort(v, l, m);
    int y = mergesort(v, m + 1, r);
    return x + y + inv(v, l, m, r);
  }
  else return 0;
}

int main(){
  int n;
  while(cin >> n){
    vector <int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    cout << mergesort(v, 0, v.size()-1) << endl;
  }
}
