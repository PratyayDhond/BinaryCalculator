#include "conversion.h"

void initInfixList(Infix *infix, int size){
    infix -> next = (List *) malloc ( sizeof(List *) * size);
    infix -> count = 0;
return;
}

void createInfix(Infix *infix, List l){
    infix->next[infix->count++] = l;
}

void displayInfix(Infix infix){

    for(int i = 0; i < infix.count ; i++)    
        displayNumber( infix.next[i]);

}