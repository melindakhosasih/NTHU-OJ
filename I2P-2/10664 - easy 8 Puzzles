#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
using State = vector<int>;

set<State> extend(State s);
set<State> explore;

int main() {
    int n;
    State goal = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    cin >> n;
    while(n--) {
        set<State> paths;
        State board;
        for(int i = 0; i < 9; i++) {
            int num;
            cin >> num;
            board.push_back(num);
        }
        paths.insert(board);
        int ans = -1, cnt = 0;
        if(board == goal) ans = 0;
        while(!paths.empty() && ans == -1) {
            if(cnt > 14) break;
            cnt++;
            set<State> newPath;
            for(auto path : paths) {
                if(ans != -1) break;
                set<State> explored = extend(path);
                for(auto state : explored) {
                    if(state == goal) {
                        ans = cnt;
                        break;
                    }
                    else newPath.insert(state);
                }
            }
            paths.erase(paths.begin());
            for(auto add : newPath) {
                paths.insert(add);
            }
        }
        if(ans == -1) cout << "You'd better skip this game.\n";
        else cout << "You can solve it within " << ans << " steps.\n";
        explore.clear();
    }
}

set<State> extend(State s) {
    set<State> newState;
    int loc;
    for(int i = 0; i < 9; i++) if(s[i] == 0) loc = i;
    if(loc%3-1 >= 0) {
        State ss = s;
        swap(ss[loc], ss[loc-1]);
        if(explore.find(ss) == explore.end()) {
            newState.insert(ss);
            explore.insert(ss);
        }
    }
    if(loc%3+1 < 3) {
        State ss = s;
        swap(ss[loc], ss[loc+1]);
        if(explore.find(ss) == explore.end()) {
            newState.insert(ss);
            explore.insert(ss);
        }
    }
    if(loc - 3 >= 0) {
        State ss = s;
        swap(ss[loc], ss[loc-3]);
        if(explore.find(ss) == explore.end()) {
            newState.insert(ss);
            explore.insert(ss);
        }
    }
    if(loc + 3 < 9) {
        State ss = s;
        swap(ss[loc], ss[loc+3]);
        if(explore.find(ss) == explore.end()) {
            newState.insert(ss);
            explore.insert(ss);
        }
    }
    return newState;
}
