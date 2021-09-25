#include <iostream>
#include <string.h>
#include "function.h"
Str::Str(char* ch) {
    int i, len;
    head = new Char(*ch);
    len = strlen(ch);
    for(i = 1, tail = head; i < len; i++, tail = tail->next)
        tail->next = new Char(ch[i]);
}
Str::Str(const Str &str) {
    head = new Char(str.head->text);
    Char *temp = str.head->next;
    for(tail = head; temp; tail = tail->next, temp = temp->next)
        tail->next = new Char(temp->text);
}
Str& Str::strInsert (const Str &St) {
    Str *temp = new Str(St);
    tail->next = temp->head;
    tail = temp->tail;
    return *this;
}
