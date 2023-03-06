#include "conversion.h"
// #include<signal.h>

// int exitSignal = true;

// void sighandler(int){
    // exitSignal = false;
// }    

int getSizeOfList(char * str){
    int size = 0;
    while(str[size] != '\0')
        size++;
    return size;
}

int getNumberOfLists(char * str){
    char *p = str;
    int count = 0;
    int isNumberFlag = false;
    while(*p != '\0'){
        if(isdigit(*p))
            isNumberFlag = true;
        else{
            if(*p  == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%' || *p == '(' || *p == ')' || *p == '^' || *p == '>' || *p == '<'){
                // if(*(p+1) == '+' || *(p+1) == '-' || *(p+1) == '*' || *(p+1) == '/' || *(p+1) == '%' || *(p+1) == '(' || *(p+1) == ')' || *(p+1) == '^'){
                    // printf("Incorrect Syntax! More operators than required\n");
                    // exit(0);
                // }
                count++;
            }else{
                printf("Incorrect Syntax! Invalid operator \'%c\' used\n",(*p));
                exit(0);
            }
        }
        p++;
    }
    if(isNumberFlag == true)
        count++;
    
    // char *p = str;
    // int count = 0;
    // if(isdigit(str[0]))
    //     count++; 
    // while(*p != '\0'){
    //     if(*p  == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%' || *p == '^'){
    //         count++;
    //     }    
    //     p++;
    // }
    return count;
}

int getNumberOfOperators(char * input){
    int count = 0;
    char *p = input;

    while(*p != '\0'){
        if(*p  == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%' || *p == '(' || *p == ')' || *p == '^' || *p == '>' || *p == '<'){
            count++;
        }
        p++;
    }
return count;
}



int main(){
    printf("lightning-bc v1\n");
    printf("Supported Operations | +,-,*,/,^,%% |\n");
    printf("Press \'ctrl + C\' to exit\n");

    char input[100];

    while(true){
    printf(">> ");
    int i = 0;
    char c;
    do{ 
        scanf("%c",&c);
        if( c == '\n')
        input[i++] = '\0';
        else if(c == ' '){
        }else
        input[i++] = c;
    }while(c != '\n');
    
    int numberOfLists = getNumberOfLists(input);
    int numberOfOperators = getNumberOfOperators(input);
    if(numberOfLists <= numberOfOperators){
        printf("Invalid Syntax Error! [More operators than operands used] \n");
        exit(0);
    }
    
    List l[numberOfLists];
    List operators[numberOfOperators];
    int j = 0;
   
    // Creating the lists as per the input given by the user
    char *p = input;
    int operandIndex = 0;    
    int operatorIndex = 0;
    Infix infix;
    initInfixList(&infix,numberOfLists + numberOfOperators);

// Not errorgenous any more
//errorgenous while loop
    while(*p != '\0'){
        while(*p == ' ')
            p++;

        if(isdigit(*p)){
            initList(&l[operandIndex]);
            while(isdigit(*p)){
                char c = *p;
                pushFront(&l[operandIndex], c);
                p++;
            }
            // displayNumber(l[operandIndex]);
            createInfix(&infix, l[operandIndex]);
            operandIndex++;
        }
        else{
            initList(&operators[operatorIndex]);
                char c = *p;
                    pushFront(&operators[operatorIndex],c);        
                p++;
            createInfix(&infix, operators[operatorIndex]);
            operatorIndex++;
        }
    }

    Postfix postfix;
    initPostfixList(&postfix,numberOfLists + numberOfOperators);
    postfix = createPostfix(infix);
    // displayPostfix(postfix);
    printf("\n");
    displayNumber(evaluatePostfix(postfix));
    printf("\n");
    }

return 0;
}