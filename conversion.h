// Todo write an infix to postfix conversion code
// The stack should be a stack of LinkedList as created in the other header
#include "stacks.h"

typedef struct Infix{
    List * next;
    int count;
}Infix;

void initInfixList(Infix *infix, int size);
void createInfix(Infix *infix, List l);
void displayInfix(Infix infix);

typedef struct Postfix{
    List * next;
    int count;
}Postfix;

void initPostfixList(Postfix *postfix, int size);
Postfix createPostfix(Infix infix);
void displayPostfix(Postfix postfix);
