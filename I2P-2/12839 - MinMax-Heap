#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset <int > data;
    string cmd;
    while(cin >> cmd) {
        if(cmd == "PUSH") {
            int num;
            cin >> num;
            data.insert(num);
        }
        else if(cmd == "POPMIN") {
            if(!data.empty()) data.erase(data.begin());
        }
        else if(cmd == "POPMAX") {
            if(!data.empty()) {
                auto del = data.end();
                del--;
                data.erase(del);
            }
        }
        else if(cmd == "MIN") {
            if(!data.empty()) cout << *data.begin() << endl;
            else cout << "Null" << endl;
        }
        else if(cmd == "MAX") {
            if(!data.empty()) {
                auto del = data.end();
                del--;
                cout << *del << endl;
            }
            else cout << "Null" << endl;
        }
        else if(cmd == "CLEAR") {
            data.clear();
        }
    }
}
