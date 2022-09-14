#include <iostream>
#include <set>
using namespace std;

int main (){
    int n;
    set <int> parents, all;
    while(cin >> n) {
        if(n == 0) break;
        int parent, child, root;
        all.clear();
        parents.clear();
        while(n--) {
            cin >> parent >> child;
            all.insert(parent);
            all.insert(child);
            parents.insert(parent);
        }
        cin >> root;
        cout << all.size() - parents.size() << endl;
    }
}
