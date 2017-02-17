#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

int main(){
  priority_queue<int, vector<int>, greater<int> > pq;
  int x;
  string y;
  while(getline(cin, y)){

    istringstream ss(y);
    while(ss >> x) pq.push(x);
    bool tipus;
    int llarg = 0;
    int mllarg = 0;

    if(!pq.empty()){
      if(pq.top()%2 == 0) tipus = true;
      else tipus = false;
      llarg = mllarg = 1;
      pq.pop();
    }
      while(!pq.empty()){
        if((pq.top()%2 == 0 and tipus) or (pq.top()%2 != 0 and not tipus)) {
          if(pq.top()%2 == 0) tipus = true;
          else tipus = false;
          pq.pop();
        }

        else if((pq.top()%2 == 0 and not tipus) or (pq.top()%2 != 0 and tipus)) {
          ++ llarg;
          if (llarg > mllarg) mllarg = llarg;
          if (pq.top()%2 == 0) tipus = true;
          else tipus = false;
          pq.pop();
        }
      }

    cout << mllarg << endl;
  }
}
