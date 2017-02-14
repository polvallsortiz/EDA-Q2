#include <iostream>
#include <queue>
using namespace std;

int main() {
  priority_queue<int> Q;
  int n;
  char c;
  while(cin >> c){
    if (c == 'S' or c == 'I' or c == 'D') cin >> n;
    if (c == 'S'){
      Q.push(n);
    }
    else if (c == 'A'){
      if(Q.empty()) cout << "error!" << endl;
      else cout << Q.top() << endl;
    }
    else if (c == 'R'){
      if(Q.empty()) cout << "error!" << endl;
      else {
        Q.pop();
      }
    }
    else if(c == 'I'){
      if(Q.empty()) cout << "error!" << endl;
      else {
        int aux = Q.top();
        Q.pop();
        Q.push(aux+n);
      }
    }
    else if (c == 'D'){
      if(Q.empty()) cout << "error!" << endl;
      else {
        int aux = Q.top();
        Q.pop();
        Q.push(aux-n);
      }
    }
    else cout << "error!"<< endl;
  }
}
