#include "function.h"

int key_count(string str) {
    int key = 0, base = 1;
    for(int i = str.length()-1; i >= 0; i--) {
        int c = str[i];
        c %= 41;
        base %= 41;
        key += c*base;
        key %= 41;
        base *= 6;
    }
    return key;
}

void Implement::Add(const string &str) {
    int key = key_count(str);
    for(string check : table[key])
        if(check == str) return;
    table[key].push_back(str);
}

void Implement::Delete(const string &str) {
    int key = key_count(str);
    list<string>::iterator itr;
    for(itr = table[key].begin(); itr != table[key].end(); itr++) {
        if(*itr == str) {
            table[key].erase(itr);
            return;
        }
    }
}

bool Implement::Exist(const string &str) {
    int key = key_count(str);
    for(string check : table[key])
        if(check == str) return true;
    return false;
}
