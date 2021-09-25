#include <stdio.h>
int main(){
    int len, cases, index, index2;
    char str[200005], a, b, store[30];
    scanf("%d%d", &len, &cases);
    scanf("%s", str);
    for(int i = 0; i < 26; i++) store[i] = i + 'a';
    while(cases--){
        scanf(" %c %c", &a, &b);
        for(int i = 0; i < 26; i++){
            if(store[i] == a) index = i;
            else if(store[i] == b) index2 = i;
        }
        if(a != b){
            store[index] = b;
            store[index2] = a;
        }
    }
    for(int i = 0; i < len; i++) printf("%c", store[str[i] - 'a']);
    printf("\n");
}
