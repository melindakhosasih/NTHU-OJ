#include <iostream>
#include <sstream>
#include "function.h"
using namespace std;
Human::Human(string n, int m, int ski) : name(n), money(m), skill(ski), bets(0), cards(0) {}
Human::~Human() {}

void Human::Draw() {
    this->cards = 0;
    string res = "";
    while (res.size() <= 0)
    getline(cin, res);
    stringstream ss(res);
    while (ss >> res) {
        int temp = 0;
        for (auto i : res)
            temp = temp * 10 + i - '0';
        this->cards += temp;
    }
}

Guard::Guard(int ski) : Human("Guard", 0, ski) {}

void Guard::Pay(Human *human) {
    if(human->skill > skill) {
        money -= human->skill - skill;
        human->money += human->skill - skill;
    }
}

Banker::Banker(int ski) : Human("Banker", 0, ski) {}
Banker::~Banker() {}

void Banker::Pay(Human *human) {
    if(human->name == "Guard") {
        money -= 100;
        human->money += 100;
    }
    else {
        int paying, bonus = 0;
        if(human->skill < skill) bonus = 10*human->cards;
        paying = bonus + human->bets;
        if(human->cards == 21) paying *= 2;
//        cout << endl;
//        cout << paying << endl;
//        cout << endl;
        human->money += paying;
        money -= paying;
    }
}

int Banker::Win(Human *human) {
    if(human->cards <= 21 && (cards > 21 || human->cards > cards)) return 0;
    else if(cards <= 21 && (human->cards > 21 || cards >= human->cards)) return 1;
    else return 2;
}

Server::Server(int ski) : Human("Server", 0, ski) {}
Server::~Server() {}

Player::Player(string name, int m, int ski) : Human(name, m, ski) {}
Player::~Player() {}

void Player::Bet() {
    cin >> bets;
}

void Player::Pay(Human *human) {
    if(money > 0) {
        if(money <= bets) {
            if(money > 0) human->money += money;
            money = 0;
        }
        else {
            money -= bets;
            human->money += bets;
        }
    }
    else money = 0;
}

bool Player::Bankrupt() {
    if(money <= 0) return true;
    else return false;
}

bool Player::Cheat(Human *human) {
    if(human->name == "Banker") {
        int paying, bonus = 0;
        if(skill < human->skill) bonus = 10*cards;
        paying = bonus + bets;
        if(cards == 21) paying *= 2;
        if(skill*3 < paying) return true;
        else return false;
    }
}

void Player::Order(Human *banker, Human *server) {
    if(money > server->skill) {
        if(money < 3000) {
            money = 0;
            return;
        }
        banker->money += 2000;
        server->money += 1000;
        money -= 3000;
    }
}

Casino::Casino() : fee(0), U(0), player_num(0), total_income(0), today_income(0), blacklist_num(0) {}
Casino::~Casino() {}

void Casino::Enterance(int f, int u) {
    fee = f;
    U = u;
}

void Casino::Guest(string s, int m, int ski) {
    for(int i = 0; i < blacklist_num; i++)
        if(blacklist[i] == s) return;
    for(int i = 0; i < player_num; i++)
        if(player[i]->name == s) return;
    if(m <= fee) {
        blacklist[blacklist_num] = s;
        blacklist_num++;
        return;
    }
    player[player_num] = new Player(s, m-fee, ski);
    player_num++;
    today_income += fee;
}

void Casino::TwentyOne() {
    int record[1009];
    int banker_ski, guard_ski, server_ski;
    for(int i = 0; i < 1009; i++) record[i] = 0;
    cin >> banker_ski >> guard_ski >> server_ski;
    banker = new Banker(banker_ski);
    guard = new Guard(guard_ski);
    server = new Server(server_ski);
    int k;
    cin >> k;
    while(k--) {
        string name;
        cin >> name;
        Player *new_player = new Player(name, 0, 0);
        new_player->Bet();
        new_player->Draw();
        int flag = 1;
        for(int i = 0; i < blacklist_num; i++) {
            if(blacklist[i] == name) {
                flag = 0;
                break;
            }
        }
        if(flag == 1) {
            for(int i = 0; i < player_num; i++) {
                if(player[i]->name == name) {
                    record[i] = 1;
                    player[i]->bets = new_player->bets;
                    player[i]->cards = new_player->cards;
                    break;
                }
            }
        }
        delete new_player;
    }
    banker->Draw();

    for(int i = 0; i < player_num; i++) {
        if(record[i] == 1) {
            if (banker->Win(player[i]) == 1) {
                player[i]->Pay(banker);
                if (player[i]->Bankrupt()) {
                    blacklist[blacklist_num] = player[i]->name;
                    blacklist_num++;
                    banker->Pay(guard);
                }
            }
            else if (banker->Win(player[i]) == 0) {
                banker->Pay(player[i]);
                player[i]->Order(banker, server);
                if (player[i]->Cheat(banker)) {
                    banker->Pay(guard);
                    blacklist[blacklist_num] = player[i]->name;
                    blacklist_num++;
                    guard->Pay(player[i]);
                }
            }
        }
    }
    today_income += banker->money;
    cout << banker->money << " " << guard->money << " " << server->money << endl;
    for(int i = 0; i < player_num; i++) {
        if(record[i] == 1) cout << player[i]->name << " " << player[i]->money << endl;
    }
}

void Casino::EndDay() {
    if(today_income >= U) blacklist_num = 0;
    total_income += today_income;
    today_income = 0;
    player_num = 0;
}

void Casino::Result() {
    cout << total_income << endl;
    for(int i = 0; i < blacklist_num; i++)
        cout << blacklist[i] << endl;
}
