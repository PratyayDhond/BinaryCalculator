#include "linkedList.h"

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