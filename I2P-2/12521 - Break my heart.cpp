#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;
    while(n--) {
        string cmd;
        cin >> cmd;
        if(cmd == "insert") {
            int val;
            cin >> val;
            s.insert(val);
        }
        else if(cmd == "print") {
            if(!s.empty()) {
                cout << *s.begin();
                for(auto num : s) if(num != *s.begin()) cout << " " << num;
                cout << endl;
            }
        }
        else if(cmd == "min") {
            if(!s.empty()) cout << *s.begin() << endl;
        }
        else if(cmd == "range_erase") {
            int l, r;
            cin >> l >> r;
            s.erase(s.lower_bound(l), s.upper_bound(r));
        }
    }
    return 0;
}
