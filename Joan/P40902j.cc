#include <iostream>
#include <map>
using namespace std;

int main(){
  map<string, int> casino;
  string name, op;
  int val;
  while(cin >> name){
    cin >> op;
    map<string, int>:: iterator it = casino.find(name);
    if (op == "wins") cin >> val;
    if (op == "enters"){
      if (it != casino.end()){
        cout << name << " is already in the casino" << endl;
      }
      else {
        casino[name] = 0;
      }
    }
    else if(op == "leaves"){
      if (it == casino.end()){
        cout << name << " is not in the casino" << endl;
      }
      else {
        cout << name << " has won " << casino[name] << endl;
        casino.erase(it);
      }
    }
    else if (op == "wins"){
      if (it == casino.end()){
        cout << name << " is not in the casino" << endl;
      }
      else {
        casino[name] += val;
      }
    }
  }
  cout << "----------"<< endl;
  map<string, int>:: iterator it;
  for(it = casino.begin(); it != casino.end(); ++it){
    cout << it->first << " is winning " << it->second << endl;
  }
}
