#include <queue>
#include <iostream>
using namespace std;

int main() {
    priority_queue <int> prior;
    char op;
    while(cin >> op) {
        switch (op)
        {
            case 'S':
                int temp;
                cin >> temp;
                prior.push(temp);
                break;

            case 'A':
                if(not prior.empty()) cout << prior.top() << endl;
                else cout << "error!" << endl;
                break;

            case 'R':
                if(not prior.empty())  prior.pop();
                else cout << "error!" << endl;
                break;

            case 'I':
                int temp2;
                cin >> temp2;
                if(not prior.empty()) {
                    int aux = prior.top();
                    prior.pop();
                    prior.push(aux + temp2);
                }
                else cout << "error!" << endl;
                break;

            case 'D':
                int temp3;
                cin >> temp3;
                if(not prior.empty()) {
                    int aux2 = prior.top();
                    prior.pop();
                    prior.push(aux2-temp3);
                }
                else cout << "error!" << endl;
                break;
        }
    }
}