#include <iostream>
#include <map>
using namespace std;

int main(){
  string op, par;
  map <string, int> use;
  map <string, int>:: iterator it;
  while (cin >> op){
    if (op == "minimum?"){
      if (use.empty()) cout << "indefinite minimum" << endl;
      else {
        cout << "minimum: " << use.begin()->first << ", " << use.begin()->second << " time(s)" << endl;
      }
    }

    else if (op == "maximum?"){
      if (use.empty()) cout << "indefinite maximum" << endl;
      else {
        it = use.end();
        --it;
        cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
      }
    }

    else if(op == "store"){
      cin >> par;
      it = use.find(par);
      if (it == use.end()){
        use[par] = 1;
      }
      else use[par] += 1;
    }

    else if(op == "delete"){
      cin >> par;
      it = use.find(par);
      if (it != use.end()){
        if (it->second == 1){
          use.erase(par);
        }
        else use[par] -= 1;
      }
    }
  }
}
