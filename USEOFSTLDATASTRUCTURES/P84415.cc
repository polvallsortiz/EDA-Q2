#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
    map<string,int> bag;
    string id;
    while(cin >> id) {
        if(id == "store") {
            string name;
            cin >> name;
            if(bag.find(name) == bag.end()) bag[name] = 1;
            else ++bag[name];
        }
        else if(id == "delete") {
            string name2;
            cin >> name2;
            if(bag.find(name2) != bag.end()) {
                --bag[name2];
                if(bag[name2] == 0) bag.erase(name2);
            }
        }
        else if(id == "minimum?") {
            if(bag.size() != 0) cout << "minimum: " << bag.begin()->first << ", " << bag.begin()->second << " time(s)" << endl;
            else cout << "indefinite minimum" << endl;
        }
        else if(id == "maximum?") {
            if(bag.size() != 0) {
                map<string,int>::iterator it = bag.end();
                --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
            else cout << "indefinite maximum" << endl;
        }
    }
}















