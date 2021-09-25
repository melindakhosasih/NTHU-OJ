#include <iostream>
#include <set>
#include "function.h"

void Crossing::solve() {
    State initial {_npeople[0], _npeople[1], 0, 0, 1};
    _paths.insert(list<State> {initial});
    while(!_paths.empty()) {
        set<list<State>> newPath;
        for(auto path : _paths) {
            State currState = path.back(); //update current state (the last path)
            _explored.insert(currState); //update the explored path
            set<State> extendedState = extend(currState); //extend all possible path at current state
            cout << endl;
            for(auto newState : extendedState) {
                if(found(newState)) {
                    auto lastPath = path;
                    lastPath.push_back(newState);
                    _solutions.insert(lastPath);
                }
                else if (_explored.find(newState) == _explored.end()) {
                    auto lastPath = path;
                    lastPath.push_back(newState);
                    newPath.insert(lastPath);
                }
            }
        }
        _paths = newPath;
    }
}

State Crossing::Go(State s, int missionary, int cannibal) {
    s[0] = s[0] - s[4]*missionary;
    s[1] = s[1] - s[4]*cannibal;
    s[2] = s[2] + s[4]*missionary;
    s[3] = s[3] + s[4]*cannibal;
    s[4] = -s[4];
    return s;
}

set<State> Crossing::extend(State s) {
    set<State> nextState;
    for(int m = 0; m <= 2; m++) {
        for(int c = 0; c <= 2; c++) {
            if(m+c >= 1 && m+c <= 2) {
                State ss = Go(s, m, c);
                if(valid(ss)) nextState.insert(ss);
            }
        }
    }
    return nextState;
}

bool Crossing::valid(State s) {
    if(s[0] < 0 || s[1] < 0 || s[2] < 0 || s[3] < 0) return false;
    if((s[0] != 0 && s[0] < s[1]) || (s[2] != 0) && s[2] < s[3]) return false;
    return true;
}

bool Crossing::found(State s) {
    if(s[0] == 0 && s[1] == 0 && s[4] == -1) return true;
    else return false;
}
