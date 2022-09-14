#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pairs;
int main() {
    int n, m;
    int s, e;
    int pos = 0;
    int ans = 0;
    set<pairs> path;
    set<int> road;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s >> e;
        pairs p = make_pair(s, e);
        road.insert(s);
        path.insert(p);
    }

    auto itr = path.begin();
    while(pos != m || itr != path.end()) {
        itr = path.begin();
        int a = *road.begin();
        int b = (*itr).first;
        if(road.empty() && path.empty()) {
            ans += m - pos;
            break;
        }
        if((a == b) && (itr != path.end())) {
            if(pos < b) {
                ans += b - pos;
            } else {
                ans += pos - b;
            }
            road.erase(road.begin());
            road.insert((*itr).second);
            path.erase(itr);
            pos = b;
        } else { // remember to check if destination equal start
            if(pos < a) {
                ans += a - pos;
            } else {
                ans += pos - a;
            }
            road.erase(road.begin());
            pos = a;
        }
    }
    cout << ans << endl;
}
