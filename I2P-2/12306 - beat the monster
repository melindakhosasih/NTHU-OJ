#include <iostream>
#include <queue>
using namespace std;

struct State {
    int lvl, hp, mhp, dist;
    State(int lvl, int hp, int mhp, int dist = 0) : lvl(lvl), hp(hp), mhp(mhp), dist(dist) {}
};

bool been[20][305][405];

int main() {
    int maxlvl, hp, mhp, mdmg;
    cin >> maxlvl >> hp >> mhp >> mdmg;
    int dmg[20], heal[20];
    for(int i = 1; i <= maxlvl; i++) cin >> dmg[i] >> heal[i];
    queue<State> q;
    q.push(State(1, hp, mhp));
    while(!q.empty()) {
        State s = q.front();
        if(s.mhp == 0) break;
        q.pop();
        //level up
        if(s.lvl + 1 <= maxlvl && s.hp - mdmg > 0) {
            State add(s.lvl+1, s.hp - mdmg, s.mhp, s.dist+1);
            if(!been[add.lvl][add.hp][add.mhp]) {
                been[add.lvl][add.hp][add.mhp] = true;
                q.push(add);
            }
        }
        //attack
        if(s.hp - mdmg > 0 || s.mhp - dmg[s.lvl] <= 0) {
            State add(s.lvl, s.hp - mdmg, max(s.mhp - dmg[s.lvl], 0), s.dist+1);
            if(!been[add.lvl][add.hp][add.mhp]) {
                been[add.lvl][add.hp][add.mhp] = true;
                q.push(add);
            }
        }
        //heal
        if(s.hp - mdmg + heal[s.lvl] > 0 && hp > mdmg) {
            State add(s.lvl, min(s.hp + heal[s.lvl], hp) - mdmg, s.mhp, s.dist+1);
            if(!been[add.lvl][add.hp][add.mhp]) {
                been[add.lvl][add.hp][add.mhp] = true;
                q.push(add);
            }
        }
    }
    if(q.empty()) cout << -1 << endl;
    else cout << q.front().dist << endl;
}
