#include <iostream>
#include <map>
using namespace std;

int main (){
  int x, y, n;
  while (cin >> x >> y >> n){
    map <int, int> use;
    int itera = 1;
    bool found = false;
    use[n] = 0;
    while (!found and n <=100000000){
      if (n%2 == 0){ //n parell
        n = n/2 + x;
        if (use.find(n) == use.end()) {
          use[n] = itera;
          ++ itera;
        }
        else {
          found = true;
          cout << itera - use.find(n)->second << endl;
        }
      }
      else { //n senar
        n = 3*n + y;
        if (use.find(n) == use.end()) {
          use[n] = itera;
          ++ itera;
        }
        else {
          found = true;
          cout << itera - use.find(n)->second << endl;
        }
      }
    }
    if (n > 100000000) cout << n << endl;
  }
}
