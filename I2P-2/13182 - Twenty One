#include <iostream>
#include "function.h"
using namespace std;

Casino::Casino():fee(0), guest_num(0), guest{}, income(0), list_num(0), blacklist{} {}
Casino::~Casino() {}
Guest::Guest():name{}, money(0), skill(0) {}
Guest::~Guest() {};

void Casino::Enterance(int f) {
    fee = f;
}

void Casino::GuestEnter(string s, int m, int ski) {
    for(int i = 0; i < list_num; i++)
        if(blacklist[i] == s) return;
    for(int i = 0; i < guest_num; i++)
        if(guest[i]->get_name() == s) return;
    if(m <= fee) {
        if(m > 0) income += m;
        blacklist[list_num] = s;
        list_num++;
        return;
    }
    guest[guest_num] = new Guest(s, m-fee, ski);
    income += fee;
    guest_num++;
}

void Casino::Win(string s, int m) {
    for(int i = 0; i < list_num; i++)
        if(blacklist[i] == s) return;
    for(int i = 0; i < guest_num; i++) {
        if(guest[i]->get_name() == s) {
            if(m < 0) {
                if(guest[i]->get_money() <= -m) {
                    income += guest[i]->get_money();
                    blacklist[list_num] = s;
                    list_num++;
                }
                else {
                    guest[i]->Win(m);
                    income -= m;
                }
            }
            else if (m > 0) {
                if(m > guest[i]->get_skill()*2) {
                    blacklist[list_num] = s;
                    list_num++;
                }
                guest[i]->Win(m);
                income -= m;
            }
            return;
        }
    }
}

void Casino::EndDay() {
    guest_num = 0;
}

void Casino::Result() {
    cout << income << endl;
    for(int i = 0; i < list_num; i++)
        cout << blacklist[i] << endl;
}

Guest::Guest(string s, int m, int ski) {
    name = s;
    money = m;
    skill = ski;
}

string Guest::get_name() {
    return name;
}

int Guest::get_money() {
    return money;
}

int Guest::get_skill() {
    return skill;
}

void Guest::Win(int m) {
    money += m;
}
