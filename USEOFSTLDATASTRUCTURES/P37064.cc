#include <iostream>
#include <set>
using namespace std;

int main() {
    set<string> st;
    string actual;
    cin >> actual;
    st.insert(actual);
    if(actual != "END") {
        cout << actual << endl;
        cin >> actual;
        set<string>::iterator it = st.begin();
        while(actual != "END") {
            st.insert(actual);
            if(st.size() % 2 != 0 and actual > *it) ++it;
            else if(st.size() % 2 == 0 and actual < *it) --it;
            cout << *it << endl;
            cin >> actual;
        }
    }
}