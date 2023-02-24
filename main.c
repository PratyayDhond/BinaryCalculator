#include "conversion.h"

int getSizeOfList(char * str){
    int size = 0;
    while(str[size] != '\0')
        size++;
    return size;
}

int getNumberOfLists(char * str){
    char *p = str;
    int count = 0;
    if(isdigit(str[0]))
        count++; 
    while(*p != '\0'){
        if(*p  == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%' || *p == '^'){
            count++;
        }    
        p++;
    }
    return count;
}

int getNumberOfOperators(char * input){
    int count = 0;
    char *p = input;

    while(*p != '\0'){
        if(*p  == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%' || *p == '(' || *p == ')' || *p == '^'){
            count++;
        }
        p++;
    }
return count;
}

int main(){
    // List l;
    // initList(&l);
    // char input[100];
    // scanf("%s",input);

    // char input[100] = "20134 * 517 + 51764691 * 21681568174 ^ 69 * (169 + 124123 * 1124124 + 1576914)";
    // char input[100] = "20134 * 517 + 51764691 * 21681568174 ^ 69 * (169 + 124123 * 1124124 + 1576914)";
    // char input[500] = "0 * 5000 + 51764691 * 21681568174 ^ 69 * (169 + 124123 * 1124124 + 1576914)";
    // char input[500] = "5000 * 0 + 51764691 * 21681568174 ^ 69 * (169 + 124123 * 1124124 + 1576914)";
    // char input[500] = "5000 * 5000 + 51764691 * 21681568174 ^ 69 * (169 + 124123 * 1124124 + 1576914)";
    // char input[500] = "12345678909876543 * 765434567890098765 + 51764691 * 21681568174 ^ 69 * (169 + 124123 * 1124124 + 1576914)";
    // char input[100] = " 51764691 * 21681568174 ^ 69 * (169 + 124123 * 1124124 + 1576914)";
    // char input[100] = "500 * 511 + 51764691 * 21681568174 ^ 69 * (169 + 124123 * 1124124 + 1576914)";
    // char input[100] = "517 * 2168 + 51764691 * 21681568174 ^ 69 * (169 + 124123 * 1124124 + 1576914)";
    char input[100] = "21685 * 517 + 51764691 * 21681568174 ^ 69 * (169 + 124123 * 1124124 + 1576914)";
    
    int numberOfLists = getNumberOfLists(input);
    int numberOfOperators = getNumberOfOperators(input);
    List l[numberOfLists];
    List operators[numberOfOperators];
    int j = 0;
   
   
    // Creating the lists as per the input given by the user
    char *p = input;
    int operandIndex = 0;    
    int operatorIndex = 0;
    Infix infix;
    initInfixList(&infix,numberOfLists + numberOfOperators);

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
            // while(!isdigit(*p)){
                char c = *p;
                // Skipping the 'Blank Spaces, by Taylor Swift' ;)
                    pushFront(&operators[operatorIndex],c);        
                p++;
                // the below lines of codes were needed for the while loop, not needed any
                // if(*p == '\0')
                    // break;
            // }
            // displayNumber(operators[operatorIndex]);
            createInfix(&infix, operators[operatorIndex]);
            operatorIndex++;
        }
    }

    // for(int i = 0; i < numberOfLists; i++){
    //     initList(&l[i]);

    //     // to avoid segmentation fault as size of Operators list is 1 less than that of operators
    //     if(i < numberOfLists - 1)
    //         initList(&operators[i]);
        
    //     while( isdigit(input[j]) )
    //         pushFront(&l[i],input[j++]);
        
    //     while(!isdigit(input[j])){
    //         if(i < numberOfLists-1){
    //             // Skipping the 'Blank Spaces, by Taylor Swift' ;)
    //             if(input[j] != ' ')
    //                 pushFront(&operators[i], input[j]);        
    //         }
    //         j++;
    //     }

    //     // displayList(l[i]);
    //     // displayList(operators[i]);
    // }

    
    


    // for(int i = 0; i < numberOfLists; i++){
    //     createInfix(&infix,l[i]);
    //     if( i < numberOfLists - 1)
    //         createInfix(&infix,operators[i]);
    // }

    displayInfix(infix);
    printf("\n");
    
    Postfix postfix;
    initPostfixList(&postfix,numberOfLists + numberOfOperators);
    postfix = createPostfix(infix);
    displayPostfix(postfix);
    // evaluatePostfix(postfix);
    printf("\n");
 
    // StackOfList s;
    // initStackOfList(&s,numberOfLists * 2 - 1 );
    // for( int i = 0; i < s.size; i++){
    //     pushToStackOfList(&s,l[i]);
    //     if( i < numberOfLists - 1)
    //         pushToStackOfList(&s, operators[i]);
    // }

    // // for( int i = 0; i < s.size; i++){
    //     displayList(popFromStackOfList(&s));
    // }

}