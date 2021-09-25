#include <iostream>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;
queue<int> country[3];
list<int> line;

int main() {
    int n;
    cin >> n;
    while(n--) {
        string cmd;
        cin >> cmd;
        if(cmd == "ENQUEUE") {
            int ID;
            cin >> ID;
            int num = ID % 3;
            country[num].push(ID);
            if(find(line.begin(), line.end(), num) == line.end()) line.push_back(num);
        }
        else if(cmd == "DEQUEUE") {
            int num = line.front(); //front & bank for the value, begin & end for iterator
            cout << country[num].front() << endl;
            country[num].pop();
            if(country[num].empty()) line.pop_front();
        }
    }
}
