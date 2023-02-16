#include "conversion.h"

void initInfixList(Infix *infix, int size){
    infix -> next = (List *) malloc ( sizeof(List *) * size);
    infix -> count = 0;
return;
}

void createInfix(Infix *infix, List l){
    infix->next[infix->count++] = l;
return;
}

void displayInfix(Infix infix){
    
    for(int i = 0; i < infix.count ; i++){
        displayNumber(infix.next[i]);
    }    

}


void pushToPostfix(Postfix *postfix, List l);
void initPostfixList(Postfix *postfix, int size){
    postfix -> next = (List *) malloc (sizeof( List *) * size);
    postfix -> count = 0;
return;
}

int priority(List l){
    if(l -> next != NULL)
        return 3;
    char x = l -> data;
    if(x == '*' || x == '/' || x =='%')
        return 2;
    if(x == '+' || x == '-')
        return 1;
    return 0;
}

Postfix* createPostfix(Infix infix, List l){
    StackOfList temp;
    initStackOfList(&temp, infix.count);
    Postfix postfix;
    initPostfixList(&postfix,infix.count);

    for(int i = 0; i < infix.count; i++){
        if(isdigit(infix.next[i]->data)){
            //BOOKMARK
            perror("It is a digit");
            pushToPostfix(&postfix,infix.next[i]);
        }else if(infix.next[i]->data == '('){
            pushToStackOfList(&temp,infix.next[i]);
        }else if(infix.next[i]-> data == ')'){
            List tempList;
            while((tempList = popFromStackOfList(&temp))->data != '('){
                //BOOKMARK
                displayList(tempList);
                pushToPostfix(&postfix, tempList);
            }  
        }
    }
}

void pushToPostfix(Postfix *postfix, List l){
    postfix->next[postfix->count++] = l;
return;
}


void displayPostfix(Postfix postfix);