#include <map>
#include <iostream>
using namespace std;

int even(int n, int x) {
    return (n/2+x);
}

int odd(int n, int y) {
    return(3*n+y);
}


int main() {
    int x,y,n;
    while(cin >> x >> y >> n) {
        bool trobat = false;
        int pos = 2;
        map<int,int> collatz;
        collatz[n] = 1;
        while(not trobat and n <= 100000000) {
            if(n % 2 == 0) n = even(n,x);
            else n = odd(n,y);
            if(collatz.find(n) != collatz.end()) {
                trobat = true;
                cout << pos - collatz[n] << endl;
            }
            else collatz[n] = pos;
            ++pos;
        }
        if(not trobat) cout << n << endl;
    }
}
