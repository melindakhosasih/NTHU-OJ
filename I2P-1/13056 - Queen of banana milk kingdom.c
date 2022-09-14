#include <stdlib.h>
#include <string.h>
#define minn(a,b) (a < b) ? a : b
typedef struct {
	int num;
	char* name;
} Monkey;

Monkey* CreateMonkeyArray(int);
void FreeMonkeyArray(Monkey*, int);
void SetVal(Monkey*, int, int, char[]);
int Compare(Monkey*, int, int);
void Swap(Monkey*, int, int);

Monkey* CreateMonkeyArray(int n) {
    Monkey* arr = (Monkey*)calloc(n, sizeof(Monkey));
    for(int i = 0; i < n; i++) arr[i].name = (char*)calloc(55, sizeof(char));
    return arr;
}

void FreeMonkeyArray (Monkey* arr, int n) {
    for(int i = 0; i < n; i++) free(arr[i].name);
    free(arr);
}

void SetVal(Monkey* arr, int i, int num, char* c) {
    arr[i].num = num;
    strcpy(arr[i].name, c);
}

int Compare (Monkey* arr, int i, int j) {
    if(arr[i].num < arr[j].num) return 1;
    if(arr[i].num > arr[j].num) return 0;
    int len = minn(strlen(arr[i].name), strlen(arr[j].name));
    for(int k = 0; k < len; k++){
        if(arr[i].name[k] < arr[j].name[k]) return 1;
        if(arr[i].name[k] > arr[j].name[k]) return 0;
    }
    return strlen(arr[i].name) < strlen(arr[j].name);
}

void Swap (Monkey* arr, int i, int j) {
    int tempnum = arr[i].num;
    arr[i].num = arr[j].num;
    arr[j].num = tempnum;
    char* tempname = arr[i].name;
    arr[i].name = arr[j].name;
    arr[j].name = tempname;
}

