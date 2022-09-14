#include <iostream>
#include "function.h"
using namespace std;

void Crossing::solve() {
    State initial {_items[0], _items[1], _items[2], 0, 0, 0, 1};
    _paths.insert(list<State> {initial});
    while(!_paths.empty()) {
        set<list<State>> newPath;
        for(auto path : _paths) {
            State currState = path.back();
            _explored.clear();
            for(auto explore : path) _explored.insert(explore);
            set<State> extendedState = extend(currState);
            for(auto state : extendedState) {
                State ss = state;
                if(found(state)) {
                    auto newState = path;
                    newState.push_back(state);
                    _solutions.insert(newState);
                }
                else if(_explored.find(state) == _explored.end()) {
                    auto newState = path;
                    newState.push_back(state);
                    newPath.insert(newState);
                }
            }
        }
        _paths = newPath;
    }
}

set<State> Crossing::extend(State s) {
    set<State> newState;
    for(int w = 0; w <= 1; w++) {
        for(int g = 0; g <= 1; g++) {
            for(int c = 0; c <= 1; c++) {
                if(w+g+c >= 0 && w+g+c <= 1) {
                    State ss = Go(s, w, g, c);
                    if(valid(ss)) {
                        newState.insert(ss);
                    }
                }
            }
        }
    }
    return newState;
}

State Crossing::Go(State s, int wolf, int goat, int cabbage) {
    s[0] = s[0] - s[6]*wolf;
    s[1] = s[1] - s[6]*goat;
    s[2] = s[2] - s[6]*cabbage;
    s[3] = s[3] + s[6]*wolf;
    s[4] = s[4] + s[6]*goat;
    s[5] = s[5] + s[6]*cabbage;
    s[6] = -s[6];
    return s;
}

bool Crossing::valid(State s) {
    if(s[0] < 0 || s[1] < 0 || s[2] < 0 || s[3] < 0 || s[4] < 0 || s[5] < 0) return false;
    if(s[6] == -1 && (s[0] > s[1] && s[1] != 0)) return false;
    if(s[6] == -1 && (s[1] > s[2] && s[2] != 0)) return false;
    if(s[6] == 1 && (s[3] > s[4] && s[4] != 0)) return false;
    if(s[6] == 1 && (s[4] > s[5] && s[5] != 0)) return false;
    return true;
}

bool Crossing::found(State s) {
    if(s[0] == 0 && s[1] == 0 && s[2] == 0) return true;
    else return false;
}
