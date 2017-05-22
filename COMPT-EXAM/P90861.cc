//
// Created by polvallsortiz on 22/05/17.
//
#include <map>
#include <string>
#include <sstream>
#include <queue>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int,queue<string> > mapa;
    for(int i = 0; i <= n; ++i) {
        string actual;
        getline(cin,actual);
        istringstream ss(actual);
        string afegir;
        while(ss >> afegir) {
            mapa[i].push(afegir);
        }
    }
    cout << "SORTIDES" << endl << "--------" << endl;
    string expressio,act;
    int actual_n;
    getline(cin,expressio);
    getline(cin,expressio);
    while(expressio.length() != 0) {
        istringstream iss(expressio);
        iss >> act;
        if(act == "SURT") {
            iss >> actual_n;
            if(actual_n > 0 and actual_n <= n and !mapa[actual_n].empty()) {
                cout << mapa[actual_n].front() << endl;
                mapa[actual_n].pop();
            }
        }
        else {
            iss >> act;
            iss >> actual_n;
            if(actual_n > 0 and actual_n <= n) mapa[actual_n].push(act);
        }
        getline(cin,expressio);
    }
    cout << endl << "CONTINGUTS FINALS" << endl << "-----------------" << endl;
    for(int j = 1; j <= n; ++j) {
        cout << "cua " << j << ":";
        while(!mapa[j].empty()) {
            cout << " " << mapa[j].front();
            mapa[j].pop();
        }
        cout << endl;
    }
}
