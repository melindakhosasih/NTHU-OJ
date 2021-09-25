#include <iostream>
#include <sstream>
#include <string>
#include "function.h"
using namespace std;

Human::~Human() {}

Guard::Guard(int ski) : Human("Guard", 0, ski) {}

Banker::Banker(int ski) : Human("Banker", 0, ski) {}

Banker::~Banker() {}

Player::Player(string name, int m, int ski) : Human(name, m, ski) {}

Human::Human(string n, int m, int ski) {
    name = n;
    money = m;
    skill = ski;
    kicked = false;
    cards = 0;
    bets = 0;
}

int Human::get_money() {
    return money;
}

void Player::Pay(Human* human) {
    if(money > 0) {
        if(money > bets) {
            money -= bets;
            human->money += bets;
        }
        else {
            human->money += money;
            money = 0;
            kicked = true;
        }
    }
    else kicked = true;
}

void Player::Bet() {
    cin >> name;
    cin >> bets;
}

void Player::Draw() {
    string card_string;
    int card;
    cards = 0;
    cin.ignore();
    getline(cin, card_string);
    istringstream input_stream(card_string);
    while(input_stream >> card) {
        cards += card;
    }
}

bool Player::Kicked() {
    return kicked;
}

bool Player::Bankrupt() {
    if(money <= 0) return true;
    else return false;
}

bool Player::Cheat(Human *human) {
    return kicked;
}

void Banker::Draw() {
    string card_string;
    int card;
    cards = 0;
    getline(cin, card_string);
    istringstream input_stream(card_string);
    while(input_stream >> card) {
        cards += card;
    }
}

int Banker::Win(Human *human) {
    if (human->cards <= 21 && (this->cards > 21 || human->cards > this->cards)) return 0;
    else if (this->cards <= 21 && (human->cards > 21 || this->cards >= human->cards)) return 1;
    else return 2;
}

void Banker::Pay(Human *human) {
    if(human->name == "Guard") {
        human->money += 100;
        money -= 100;
    }
    else {
        int paying, bonus = 0;
        if(human->skill < skill) bonus = 10*human->cards;
        paying = human->bets + bonus;
        if(human->cards == 21) paying *= 2;
        if(2*human->skill < paying) human->kicked = true;
        human->money += paying;
        money -= paying;
    }
}

void Guard::Pay(Human* human) {
    human->money += human->skill - skill;
    money -= human->skill - skill;
}

void Guard::Kick(Human *human, int flag) {
    if(flag == 1) {
        if(skill < human->skill) {
            Pay(human);
        }
    }
    human->kicked = true;
}
