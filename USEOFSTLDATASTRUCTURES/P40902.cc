#include <map>
#include <iostream>
#include <string>
using namespace std;

bool inside(string name,const map<string,int>& map1) {
    map<string,int>::const_iterator it = map1.find(name);
    return (it != map1.end());
}

void final(const map<string,int>& map1) {
    map<string,int>::const_iterator it = map1.begin();
    while(it != map1.end()) {
        cout << it->first << " is winning " << it->second << endl;
        ++it;
    }
}

int main() {
    map<string,int> casino;
    string name,action;
    while(cin >> name >> action) {
        if(action == "enters") {
            cerr << "ENTRO ENTERS" << endl;
            if(inside(name,casino)) cout << name << " is already in the casino" << endl;
            else casino[name] = 0;
        }
        else if(action == "wins") {
            cerr << "ENTRO WINS" << endl;
            if(not inside(name,casino)) cout << name << " is not in the casino" << endl;
            else {
                int entrada;
                cin >> entrada;
                casino[name] += entrada;
            }
        }
        else if(action == "leaves") {
            cerr << "ENTRO LEAVES" << endl;
            if(not inside(name,casino)) cout << name << " is not in the casino" << endl;
            else {
                cout << name << " has won " << casino[name] << endl;
                casino.erase(name);
            }
        }
    }
    cout << "----------" << endl;
    final(casino);
}