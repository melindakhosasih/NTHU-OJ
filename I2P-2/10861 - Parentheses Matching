#include <iostream>
#include <string>
using namespace std;

int check(char a, char b) {
    if(a == '(') return b == ')';
    else if(a == '<') return b == '>';
    else if(a == '{') return b == '}';
    else if(a == '[') return b == ']';
    else return 0;
}

int main() {
    int n;
    int cases = 1;
    cin >> n;
    getchar();
    while(n--) {
        char arr[1005] = {0};
        string str;
        getline(cin, str);
        int len = str.size();
        int idx = -1;
        int flag = 1;
        for(auto c = str.begin(); c != str.end(); c++) {
            if(*c == '(' || *c == '<' || *c == '[' || *c == '{') arr[++idx] = *c;
            else {
                if(check(arr[idx], *c) && idx >= 0) idx--;
                else {
                    flag = 0;
                    break;
                }
            }
        }
        if(idx >= 0) flag = 0;
        cout << "Case " << cases << ": ";
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
        cases++;
    }
}
