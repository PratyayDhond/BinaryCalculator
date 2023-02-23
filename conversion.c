#include "conversion.h"
#include "binaryCalculator.h"

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

int isOperator(char x){
    if( x == '^' || x == '*' || x == '/' || x == '+' || x == '-' || x == '%')
        return true;
    return false;
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

    for(int i = 0; i < infix.count ; i++){
        if(isdigit(infix.next[i]->data)){
            pushToPostfix(&postfix,infix.next[i]);
        }else if(infix.next[i] -> data == '('){
            pushToStackOfList(&temp, infix.next[i]);
        }else if(infix.next[i] -> data == ')'){
            List tempList = popFromStackOfList(&temp);
            while(tempList && tempList -> data != '('){
                pushToPostfix(&postfix,tempList);
                tempList = popFromStackOfList(&temp);
            }
            // printf("%c\n",tempList ->data);
        }else if(isOperator(infix.next[i]->data)){
            if(isEmptyStackOfList(temp)){
                pushToStackOfList(&temp,infix.next[i]);
            }else{
                if(priority(infix.next[i]->data) > priority(peekFromStackOfList(temp) -> data)){
                    pushToStackOfList(&temp, infix.next[i]);
                }else if( priority(infix.next[i] -> data) == priority(peekFromStackOfList(temp)->data && infix.next[i] -> data == '^')){
                    pushToStackOfList(&temp, infix.next[i]);
                }else{
                    while(!isEmptyStackOfList(temp) && priority(infix.next[i] -> data) <= priority(peekFromStackOfList(temp) -> data)){
                        pushToPostfix(&postfix, popFromStackOfList(&temp));
                    }
                    pushToStackOfList(&temp, infix.next[i]);
                }
            }
        }
    }

    while(!isEmptyStackOfList(temp)){
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

    printf("\n");
    displayNumber(postfix.next[0]);
    printf("\n");
    displayNumber(postfix.next[1]);
    printf("\n");
    displayNumber(subtract(postfix.next[0], postfix.next[1]));
}

List evaluatePostfix(Postfix postfix){
    List answer,temp;
    initList(&answer);
    initList(&temp);
    StackOfList numbers;
    initStackOfList(&numbers,postfix.count);
    for(int i = 0; i < postfix.count; i++){
        if(isdigit(postfix.next[i]->data)){
            pushToStackOfList(&numbers,postfix.next[i]);
        }else{
            List num2 = popFromStackOfList(&numbers);
            List num1 = popFromStackOfList(&numbers);
        
            switch(postfix.next[i] -> data){
                case '^':
                            temp = toThePower(num1,num2);
                            break;
                case '*':
                            temp = multiply(num1, num2);
                            break;
                case '/':
                            // add is list of zeroes function
                            temp = divide(num1, num2);
                            break;
                case '+':
                            temp = add(num1, num2);
                            break;
                case '-':
                            temp = subtract(num1, num2);
                            break;
                case '%':
                            temp = mod(num1, num2);
                            break;
                default :
                            printf("Incorrect operator detected. FORCE EXITTING!");
                            return NULL;
                            break;
            }
//push to stacck of numbers temp
        }
    }

    return answer;   
}