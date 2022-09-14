#include <iostream>
#include <queue>
#include <list>
using namespace std;

list<queue<int>> line;

int main() {
    int n;
    cin >> n;
    while(n--) {
        string cmd;
        cin >> cmd;
        if(cmd == "ENQUEUE") {
            int ID;
            cin >> ID;
            auto itr = line.begin();
            for(; itr != line.end(); itr++) {
                if((*itr).front() % 3 == (ID % 3)) break;
            }
            if(itr == line.end()) {
                queue<int> country;
                country.push(ID);
                line.push_back(country);
            }
            else {
                (*itr).push(ID);
            }
        }
        else if(cmd == "DEQUEUE") {
            auto itr = line.begin();
            cout << (*itr).front() << endl;
            (*itr).pop();
            if((*itr).empty()) line.pop_front();
        }
    }
}
