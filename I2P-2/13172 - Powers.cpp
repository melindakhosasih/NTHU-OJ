#include <iostream>
#include <string>
#include <math.h>
#include "function.h"

special_power::special_power(int n) {
    this->n = n;
}

int special_power::fpow(int x) {
    int power = n;
    long long ans = 1;
    long long base = x;
    base = base % 880301;
    if(base == 0) return 0;
    while(power > 0) {
        if (power % 2 == 1)
            ans = ans*base % 880301;
        power = power >> 1;
        base = (base*base) % 880301;
    }
    return ans;
}

int special_power::fpow(int x, int m) {
    int power = n;
    long long ans = 1;
    long long base = x;
    base = base % m;
    if(base == 0) return 0;
    while(power > 0) {
        if (power % 2 == 1)
            ans = ans*base % m;
        power = power >> 1;
        base = (base*base) % m;
    }
    return ans;
}

int special_power::fpow() {
    int power = n;
    long long ans = 1;
    long long base = 2;
    while (power > 0) {
        if (power % 2 == 1)
            ans = ans*base % 880301;
        power = power >> 1;
        base = (base*base) % 880301;
    }
    return ans;
}

string special_power::fpow(string s) {
    string ans;
    int len = s.size();
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < n; j++) {
            ans.push_back(s[i]);
        }
    }
    return ans;
}

string special_power::fpow(string s, int m) {
    string ans;
    int idx = 0;
    int len = s.size();
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < n; j++) {
            if(idx == m) return ans;
            ans.push_back(s[i]);
            idx++;
        }
    }
    return ans;
}
