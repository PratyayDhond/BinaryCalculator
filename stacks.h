#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "linkedList.h"

#endif

typedef struct StackOfList{
    List *arr;
    int top;
    int size;
    int count;
}StackOfList;

void initStackOfList(StackOfList *s, int size);
void pushToStackOfList(StackOfList *s, List l);
int isEmptyStackOfList(StackOfList s);
List popFromStackOfList(StackOfList *s);
List peekFromStackOfList(StackOfList s);