#include <set>
#include <string>
#include <iostream>
using namespace std;

bool cmp(string a, string b) {
    return (a.length() < b.length());
}

void finalize(set<string>& sin, set<string>& sout, int& n) {
    if(n != 1) cout << endl;
    cout << "GAME #" << n << endl << "HAS:" << endl;
    set<string>::iterator it = sin.begin();
    while(it != sin.end()) {
        cout << *it << endl;
        sin.erase(it);
        ++it;
    }
    cout << endl << "HAD:" << endl;
    it = sout.begin();
    while(it != sout.end()) {
        cout << *it << endl;
        sout.erase(it);
        ++it;
    }
    ++n;
}

int main() {
    set<string,cmp> sin;
    set<string,cmp> sout;
    int game = 1;
    string s;
    cin >> s;
    while(s != "QUIT") {
        if(s == "END") finalize(sin,sout,game);
        else {
            set<string>::iterator it = sin.find(s);
            set<string>::iterator it2 = sout.find(s);
            if(it == sin.end()) {
                if(it2 != sout.end()) sout.erase(it2);
                sin.insert(s);
            }
            else {
                sin.erase(it);
                sout.insert(s);
            }
        }
        cin >> s;
    }
    finalize(sin,sout,game);
}