#include <iostream>
#include <map>
using namespace std;

int main(){
  cout.setf(ios::fixed);
  cout.precision(4);
  string op;
  int val;
  double acu = 0;
  double cont = 0;
  map<int, int> mp;
  map<int, int>::iterator it;
  while(cin >> op){
    if(op == "number"){
      cin >> val;
      it = mp.find(val);
      if(it != mp.end())mp[val] += 1;
      else mp[val] = 1;
      acu += val;
      ++cont;
    }
    else if (op == "delete"){
      if(not mp.empty()){
        it = mp.begin();
        acu -= it->first;
        if (it->second == 1) mp.erase(it);
        else it->second -= 1;
        --cont;
      }
    }
    if (!mp.empty()){
      it = mp.end();
      --it;
      cout <<"minimum: "<< mp.begin()->first << ", maximum: "<< it->first << ", average: " << acu/cont<<endl;
    }
    else cout << "no elements"<< endl;
  }
}
