#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define true 1
#define false 0

typedef struct Node{
    char data;
    struct Node * next;
}Node;

typedef Node * List;

void initList(List *l);
void pushFront(List * l, char data);

char popFront(List * l);
int isEmpty(List l);

void displayList(List l);
void displayNumber(List l);