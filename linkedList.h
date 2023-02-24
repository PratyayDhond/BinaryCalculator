#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define true 1
#define false 0

typedef struct Node{
    char data;
    struct Node * next;
}Node;

// for list of numbers the first bit indicated the number's sign
// 1 is positive
// 0 is negative
typedef Node * List;

void initList(List *l);
void destroyList(List l);
void pushFront(List * l, char data);
void reverseList(List *l);

char popFront(List * l);
int isEmpty(List l);

void displayList(List l);
void displayNumber(List l);

