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
    char x = l -> data;
    if(x == '^')
        return 3;
    if(x == '*' || x == '/' || x =='%')
        return 2;
    if(x == '+' || x == '-')
        return 1;
    return 0;
}

Postfix createPostfix(Infix infix){
    StackOfList temp;
    initStackOfList(&temp, infix.count);
    Postfix postfix;
    initPostfixList(&postfix,infix.count);

    for(int i = 0; i < infix.count; i++){
        if(isdigit(infix.next[i]->data)){
            pushToPostfix(&postfix,infix.next[i]);
        }else if(infix.next[i]->data == '('){
            pushToStackOfList(&temp,infix.next[i]);
        }else if(infix.next[i]-> data == ')'){
            List tempList;
            while((tempList = popFromStackOfList(&temp))->data != '('){
                pushToPostfix(&postfix, tempList);
            }  
        }else{
            while(priority(temp.arr[temp.top]) >= priority(infix.next[i])){
                pushToPostfix(&postfix, popFromStackOfList(&temp) );
            }
            pushToStackOfList(&temp,infix.next[i]);
        }
    }
        while(temp.top != -1){
            pushToPostfix(&postfix, popFromStackOfList(&temp));
        }
    return postfix;
}

void pushToPostfix(Postfix *postfix, List l){
    postfix->next[postfix->count++] = l;
return;
}


void displayPostfix(Postfix postfix){
    for(int i = 0; i < postfix.count ; i++){
        displayNumber(postfix.next[i]);
    }        
}