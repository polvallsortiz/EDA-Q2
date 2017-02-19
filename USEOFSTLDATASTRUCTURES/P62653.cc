#include <string>
#include <map>
#include <set>
#include <queue>
#include <iostream>
using namespace std;

void finalize(map<int,set<string> >& tick_owners, const queue<string>& tick_queue, int n) {
    map<int,set<string> >::iterator itmap = tick_owners.begin();
    while(itmap != tick_owners.end()) {
        set<string> set1 = itmap->second;
        set<string>::iterator itset;
        for(itset = set1.begin(); itset != set1.end(); ++itset) cout << *itset << endl;
        tick_owners.erase(itmap);
        ++itmap;
    }
    cout << n <<  " ticket(s) left" << endl;
    cout << tick_queue.size() << " supporter(s) with no ticket" << endl << endl;
}

int main() {
    string action;
    map<int,set<string> > tick_owners;
    int n;
    while(cin >> action) {
        queue<string> tick_queue;
        char c;
        cin >> c;
        n = 0;
        while(c != 'E') {
            if(c == 'T') {
                if(not tick_queue.empty()) {    //SPECTATORS WAITING TICKETS
                    string name1 = tick_queue.front();
                    tick_owners[name1.length()].insert(name1);
                    tick_queue.pop();
                }
                else ++n;
            }
            if(c == 'S') {
                string name;
                cin >> name;
                tick_queue.push(name);
                if(n != 0) {    //TICKETS AVAIBLE
                    name = tick_queue.front();
                    tick_owners[name.length()].insert(name);
                    tick_queue.pop();
                    --n;
                }
            }
            cin >> c;
        }
        finalize(tick_owners,tick_queue,n);
    }
}