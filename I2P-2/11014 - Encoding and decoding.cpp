#include <iostream>
#include <sstream>
#include "function.h"
using namespace std;

void RleCodec::encode()
{
    stringstream str;
    int cnt = 0;
    char compare = code_str[0];
    for(auto c : code_str) {
        if(c == compare) cnt++;
        else {
            if(cnt == 1) str << compare;
            else if(cnt == 2) str << compare << compare;
            else str << cnt << compare;
            cnt = 1;
            compare = c;
        }
    }
    if(cnt == 1) str << compare;
    else if(cnt == 2) str << compare << compare;
    else str << cnt << compare;
    code_str = str.str();
    encoded = true;
}

void RleCodec::decode()
{
   stringstream str;
   string num_str;
   for(auto c : code_str) {
        if(isdigit(c)) num_str.push_back(c);
        else {
            stringstream num{num_str};
            int cnt = 0;
            num >> cnt;
            if(cnt == 0) str << c;
            else while(cnt--) str << c;
            num_str.clear();
        }
   }
   code_str = str.str();
   encoded = false;
}
