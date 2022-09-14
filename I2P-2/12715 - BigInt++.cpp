#include <iostream>
#include <string.h>
#include "function.h"
using namespace oj;
using namespace std;

BigInt::BigInt(char *s) {
    _val = new char[1030];
    strcpy(_val, s);
}

BigInt::~BigInt() {
    delete _val;
}

BigInt &BigInt::operator++() {
    char s[1030];
    strcpy(s,_val);
    int len = strlen(s) - 1;
    int carry = 0;
    int num = s[len] - '0';
    int flag = 1;
    if(num == 9) {
        s[len+1] = '0';
        s[len+2] = '\0';
        carry = 1;
        while(len--) {
            num = s[len] - '0';
            if(carry == 1) {
                if(num != 9) {
                    s[len+1] = num + '1';
                    carry = 0;
                }
                else if (num == 9) {
                    s[len+1] = '0';
                    carry = 1;
                }
            }
            else {
                flag = 0;
                s[len+1] = s[len];
                if(len == 0) s[0] = '0';
            }
        }
        if(carry == 1) s[0] = '1';
        else if (carry == 0 && flag == 1) s[0] = '0';
    }
    else {
        s[len]++;
    }
    strcpy(_val, s);
    if(s[0] == '0' && s[1] != '\0') {
        char str[1030];
        int idx = 0;
        for(int i = 0; s[i] != '\0'; i++) {
            if(idx > 0) {
                str[idx] = s[i];
                idx++;
            }
            else {
                if(s[i] != '0') idx++;
                str[0] = s[i];
            }
        }
        str[idx] = '\0';
        strcpy(_val, str);
    }
    return *this;
}

BigInt BigInt::operator++(int num) {
    BigInt temp(_val);
    char s[1030];
    strcpy(s,_val);
    int len = strlen(s) - 1;
    int carry = 0;
    int flag = 1;
    num = s[len] - '0';
    if(num == 9) {
        s[len+1] = '0';
        s[len+2] = '\0';
        carry = 1;
        while(len--) {
            num = s[len] - '0';
            if(carry == 1) {
                if(num != 9) {
                    s[len+1] = num + '1';
                    carry = 0;
                }
                else if (num == 9) {
                    s[len+1] = '0';
                    carry = 1;
                }
            }
            else {
                flag = 0;
                s[len+1] = s[len];
                if(len == 0) s[0] = '0';
            }
        }
        if(carry == 1) s[0] = '1';
        else if (carry == 0 && flag == 1) s[0] = '0';
    }
    else {
        s[len]++;
    }
    strcpy(_val, s);
    if(s[0] == '0' && s[1] != '\0') {
        char str[1030];
        int idx = 0;
        for(int i = 0; s[i] != '\0'; i++) {
            if(idx > 0) {
                str[idx] = s[i];
                idx++;
            }
            else {
                if(s[i] != '0') idx++;
                str[0] = s[i];
            }
        }
        str[idx] = '\0';
        strcpy(_val, str);
    }
    return temp;
}

BigInt &BigInt::operator--() {
    char s[1030];
    strcpy(s,_val);
    int len = strlen(s) - 1;
    int borrow = 1;
    int num = s[len] - '0';
    if(num == 0 && len != 0) {
        s[len] = '9';
        s[len+1] = '\0';
        borrow = 1;
        while(len--) {
            num = s[len] - '0';
            if(borrow == 1) {
                if(num != 0) {
                    s[len]--;
                    borrow = 0;
                }
                else if(num == 0) {
                    s[len] = '9';
                    borrow = 1;
                }
            }
            else break;
        }
    }
    else if(num != 0) {
        s[len]--;
    }
    strcpy(_val, s);
    if(s[0] == '0' && s[1] != '\0') {
        char str[1030];
        int idx = 0;
        for(int i = 0; s[i] != '\0'; i++) {
            if(idx > 0) {
                str[idx] = s[i];
                idx++;
            }
            else {
                if(s[i] != '0') idx++;
                str[0] = s[i];
            }
        }
        if(idx != 0) str[idx] = '\0';
        else {
            str[0] = '0';
            str[1] = '\0';
        }
        strcpy(_val, str);
    }
    return *this;
}

BigInt BigInt::operator--(int num) {
    BigInt temp(_val);
    char s[1030];
    strcpy(s,_val);
    int len = strlen(s) - 1;
    int borrow = 1;
    num = s[len] - '0';
    if(num == 0 && len != 0) {
        s[len] = '9';
        s[len+1] = '\0';
        borrow = 1;
        while(len--) {
            num = s[len] - '0';
            if(borrow == 1) {
                if(num != 0) {
                    s[len]--;
                    borrow = 0;
                }
                else if(num == 0) {
                    s[len] = '9';
                    borrow = 1;
                }
            }
            else break;
        }
    }
    else if(num != 0) {
        s[len]--;
    }
    strcpy(_val, s);
    if(s[0] == '0' && s[1] != '\0') {
        char str[1030];
        int idx = 0;
        for(int i = 0; s[i] != '\0'; i++) {
            if(idx > 0) {
                str[idx] = s[i];
                idx++;
            }
            else {
                if(s[i] != '0') idx++;
                str[0] = s[i];
            }
        }
        if(idx != 0) str[idx] = '\0';
        else {
            str[0] = '0';
            str[1] = '\0';
        }
        strcpy(_val, str);
    }
    return temp;
}

char* BigInt::to_s() {
    return _val;
}
