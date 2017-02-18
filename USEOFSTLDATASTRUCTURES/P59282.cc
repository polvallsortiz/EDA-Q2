#include <iostream>
#include <map>
using namespace std;

void end_action(const map<int,int>& map1, int average, int n) {
    if(not map1.empty()) {
        double av = average;
        map<int,int>::const_iterator it = map1.begin();
        cout << "minimum: " << it->first << ", maximum: ";
        it = map1.end();
        --it;
        cout << it->first << ", average: " << av/n << endl;
    }
    else cout << "no elements" << endl;
}

void delete_smallest(map<int,int>& map1, int& average, int& n) {
    if(not map1.empty()) {
        --n;
        average -= map1.begin()->first;
        --map1.begin()->second;
        if(map1.begin()->second == 0) map1.erase(map1.begin());
    }
}

int main() {
    //4 DECIMAL ACTIVATION
    cout.setf(ios::fixed);
    cout.precision(4);
    map<int,int> mp;
    int average,n;
    average = n = 0;
    string action;
    while(cin >> action) {
        if(action == "number") {
            int actual;
            cin >> actual;
            map<int,int>::iterator itadd = mp.find(actual);
            if(itadd == mp.end()) mp[actual] = 1;
            else ++mp[actual];
            average += actual;
            ++n;
        }
        else if(action == "delete") delete_smallest(mp,average,n);
        end_action(mp,average,n);
    }
}
