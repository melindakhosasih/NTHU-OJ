#include <iostream>
#include <deque>
using namespace std;

int main () {
    deque <string> data;
    string cmd;
    while(cin >> cmd) {
        if(cmd == "Push") {
            string name;
            cin >> name;
            data.push_back(name);
        }
        else if(cmd == "Pop") {
            if(!data.empty()) data.pop_front();
        }
        else if(cmd == "Front") {
            if(!data.empty()) cout << data.front() << endl;
            else cout << "empty" << endl;
        }
    }
}
