#include <iostream>
#include <sstream>
#include <list>
using namespace std;

int longest_sequence(const list<int>& list1) {
    int max = 0;
    list<int>::const_iterator it = list1.begin();
    list<int>::const_iterator itmov;
    while(it != list1.end() and max != list1.size()) {
        itmov = it;
        int primer = *it;
        ++itmov;
        int actual = *itmov;
        int len = 1;
        while(itmov != list1.end()) {
            if(actual % 2 == 0) {   //ANTERIOR PARELL
                if(*itmov % 2 != 0) ++len;   //ACTUAL IMPARELL
                else len = 1;   //ACTUAL PARELL
            }
            else {  //ANTERIOR IMPARELL
                if(*itmov % 2 == 0) ++len;   //ACTUAL PARELL
                else len = 1;  //ACTUAL IMPARELL
            }
            actual = *itmov;
            ++itmov;
        }
        if(max < len) max = len;
        ++it;
    }
    return max;
}

int main() {
    string s;
    while(getline(cin,s)) {
        list<int> ls;
        istringstream iss(s);
        int i;
        while(iss >> i) {
            ls.push_back(i);
        }
        i = longest_sequence(ls);
        cout << i << endl;
    }
}