#include <iostream>
#include <set>
using namespace std;

int main (){
  string a;
  set <string> se;
  set<string>::iterator it;
  cin >> a;
  if ( a != "END"){
    se.insert(a);
    it = se.begin();
    cout << a << endl;
    while (cin >> a and a != "END"){
      se.insert(a);
      if (a < *it and se.size()%2 == 0) --it;
      if (a > *it and se.size()%2 != 0) ++ it;
      cout << *it << endl;
    }

  }
}
