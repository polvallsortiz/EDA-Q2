#include <set>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
using namespace std;

bool cmp(string a, string b) {
    return ((a.length() > b.length()) or (a.length() == b.length() and a > b));
}

/*void erase(vector<string>& vout, string s) {
    bool trobat = false;
    int i = 0;
    while(i < vout.size() and not trobat) {
        if(vout[i] == s) {
            swap(vout[i],vout[vout.size()-1]);
            vout.pop_back();
            trobat = true;
        }
        ++i;
    }
    if(trobat) sort(vout.begin(),vout.end(),cmp);
}
 */

void finalize(set<string>& sin, map<int,set<string> >& mp, int& n) {
    if(n != 1) cout << endl;
    cout << "GAME #" << n << endl << "HAS:" << endl;
    set<string>::iterator it = sin.begin();
    while(it != sin.end()) {
        cout << *it << endl;
        sin.erase(it);
        ++it;
    }
    cout << endl << "HAD:" << endl;
    map<int,set<string> >::iterator it2 = mp.begin();
    while(it2 != mp.end()) {
        set<string> set1 = it2->second;
        set<string>::iterator itset;
        for(itset = set1.begin(); itset != set1.end(); ++itset) cout << *itset << endl;
        mp.erase(it2);
        ++it2;
    }
    ++n;
}

int main() {
    set<string> sin;
    //set<string> sout;
    map<int,set<string> > mp;
    //vector<string> vout;
    int game = 1;
    string s;
    cin >> s;
    while(s != "QUIT") {
        if(s == "END") finalize(sin,mp,game);
        else {
            set<string>::iterator it = sin.find(s);
            set<string>::iterator it2 = mp[s.length()].find(s);
            if(it == sin.end()) {
                if(it2 != mp[s.length()].end()) mp[s.length()].erase(it2);
                //erase(vout,s);
                sin.insert(s);
            }
            else {
                sin.erase(it);
                //vout.push_back(s);
                //sort(vout.begin(),vout.end(),cmp);
                mp[s.length()].insert(s);
            }
        }
        cin >> s;
    }
    finalize(sin,mp,game);
}