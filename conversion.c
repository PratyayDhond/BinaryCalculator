#include "conversion.h"

void initInfixList(Infix *infix, int size){
    infix -> next = (List *) malloc ( sizeof(List *) * size);
    infix -> count = 0;
return;
}

void createInfix(Infix *infix, List l){
    infix->next[infix->count++] = l;
    // displayList(l);
    // printf("%d\n ",infix -> count);
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

int priority(char x){
    if(x == '^')
        return 3;
    if(x == '*' || x == '/' || x =='%')
        return 2;
    if(x == '+' || x == '-')
        return 1;
    return 0;
}
//"123456789 + 34567890876 - 51764691 * 21681568174 ^ 69 * (169 + 124123 * 1124124 + 1576914)"
Postfix createPostfix(Infix infix){
    StackOfList temp;
    initStackOfList(&temp, infix.count);
    Postfix postfix;
    initPostfixList(&postfix,infix.count);

    for(int i = 0; i < infix.count; i++){
        
        if(isdigit(infix.next[i]->data)){
            perror("Line 51 - Pushing to Postfix");
            pushToPostfix(&postfix,infix.next[i]);
        }else if(infix.next[i]->data == '('){
            perror("Line 54 - Pushing operator to stack (");
            pushToStackOfList(&temp,infix.next[i]);
        }else if(infix.next[i]-> data == ')'){
            List tempList = popFromStackOfList(&temp);
            while(tempList && tempList -> data  != '('){
                perror("Line 57 - pushing operator in the stack->top to postfix");
                // if(tempList-> data != '(')
                    pushToPostfix(&postfix, tempList);
                tempList =  popFromStackOfList(&temp);
                displayList(tempList);
            }

        }else{
            // Added if condition to avoid checking priority of empty stack of operators 
            if(temp.top == -1){
               perror("Line 65 - pushing operator to stack");
                pushToStackOfList(&temp,infix.next[i]);
            }else{
                perror("Line 68 - popping from stack till condition ");
                char stackTop = temp.arr[temp.top]->data;
                char current = infix.next[i]->data;
                while( temp.top >= 0 && priority(stackTop) >= priority(current)){
                    perror("Line 73 - pushing operator to postfix");
                    List l =  popFromStackOfList(&temp);
                    displayList(l);
                    pushToPostfix(&postfix,l );
                }
                pushToStackOfList(&temp,infix.next[i]);
            }
        }
    }

        while(temp.top != -1){
            perror("Line 79");
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
        printf(" ");
    }        
}