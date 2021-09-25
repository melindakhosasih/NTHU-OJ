#include <iostream>
#include <queue>
using namespace std;

int main () {
    string cmd;
    priority_queue<int> Q;
    while(cin >> cmd) {
        if(cmd == "PUSH") {
            int val;
            cin >> val;
            Q.push(val);
        }
        else if(cmd == "POP") {
            Q.pop();
        }
        else if(cmd == "TOP") {
            if(Q.empty()) cout << "Null" << endl;
            else cout << Q.top() << endl;
        }
    }
    return 0;
}
