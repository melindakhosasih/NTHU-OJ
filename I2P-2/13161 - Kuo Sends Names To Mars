#include <iostream>
#include <string.h>
using namespace std;
int cnt = 0;
void palindrome (char *str, int len);
int main(){
    char str[100005];
    int len;
    cin >> str;
    len = strlen(str);
    palindrome(str, len);
    cout << cnt << endl;
}

void palindrome (char *str, int len) {
    int flag[100005] = {0};
    for(int i = 0; i < len-2; i++) {
            int j = i;
            j++;
            if(str[i] == str[j] && flag[i] == 0 && flag[j] == 0){
//                cout << str[i] << i << endl;
//                cout << str[j] << j << endl;
                flag[j] = 1;
                cnt++;
            }
            j++;
            if(str[i] == str[j] && flag[i] == 0 && flag[j] == 0){
                flag[j] = 1;
                cnt++;
            }
    }
}
