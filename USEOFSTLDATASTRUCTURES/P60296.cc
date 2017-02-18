#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct player {
    bool connected;
    int points;
};

bool cmp(pair<string,int> a, pair<string,int> b) {
    return((a.second > b.second) or (a.second == b.second and a.first < b.first));
}

bool created(const map<string,player>& map1, string id) {
    map<string,player>::const_iterator it = map1.find(id);
    return (it != map1.end());
}

bool connected(const map<string,player>& map1, string id) {
    bool res;
    map<string,player>::const_iterator it = map1.find(id);
    if(it != map1.end()) {
        if(it->second.connected == true) res = true;
        else res = false;
    }
    else res = false;
    return res;
}

void end(const map<string,player>& map1) {
    cout << endl << "RANKING" << endl;
    map<string,player>::const_iterator it;
    vector<pair<string,int> > vector1;
    for(it = map1.begin();it != map1.end();++it) {
        pair<string,int> pair1;
        pair1.first = it->first;
        pair1.second = it->second.points;
        vector1.push_back(pair1);
    }
    sort(vector1.begin(),vector1.end(),cmp);
    for(int i = 0; i < vector1.size(); ++i) {
        cout << vector1[i].first << " " << vector1[i].second << endl;
    }
}

int main() {
    map<string,player> mp;
    string action;
    while(cin >> action) {
        if(action == "LOGIN") {
            string name;
            cin >> name;
            if(not created(mp,name)) {
                mp[name].points = 1200;
                mp[name].connected = true;
            }
            else mp[name].connected = true;
        }
        if(action == "LOGOUT") {
            string name1;
            cin >> name1;
            if(connected(mp,name1)) mp[name1].connected = false;
            else cout << "player(s) not connected" << endl;
        }
        if(action == "PLAY") {
            string name2,name3;
            cin >> name2 >> name3;
            if(connected(mp,name2) and connected(mp,name3)) {
                mp[name2].points += 10;
                if(mp[name3].points != 1200) mp[name3].points -= 10;
            }
            else cout << "player(s) not connected" << endl;
        }
        if(action == "GET_ELO") {
            string name4;
            cin >> name4;
            if(created(mp,name4)) cout << name4 << " " << mp[name4].points << endl;
        }
    }
    end(mp);
}

