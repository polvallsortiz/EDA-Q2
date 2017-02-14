#include <queue>
#include <iostream>
using namespace std;

int main() {
    priority_queue <int> prior;
    char op;
    while(cin >> op) {
        switch (op)
        {
            case 'S:
                int temp;
                cin >> temp;
                prior.push(cin)
            case 'A':
                if(not prior.empty()) cout << prior.top() << endl;
                else cout << "error!" << endl;
                break;

            case 'R':
                if(not.prior.empty())  prior.pop();
                else cout << "error!" << endl;
                break;

            case ''
        }
    }
}