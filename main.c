#include<stdio.h>
#include<ctype.h>
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
        if(*p  == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%'){
            if(*p == '*' && *(p+1) == '*')
                p++;
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
    char* input = "123456789 + 34567890876 - 51764691 * 21681568174 ** 69";
    int numberOfLists = getNumberOfLists(input);
    List l[numberOfLists];
    List operators[numberOfLists - 1];
    int j = 0;
   
   
    // Creating the lists as per the input given by the user
    for(int i = 0; i < numberOfLists; i++){
        initList(&l[i]);

        // to avoid segmentation fault as size of Operators list is 1 less than that of operators
        if(i < numberOfLists - 1)
            initList(&operators[i]);
        
        while( isdigit(input[j]) )
            pushFront(&l[i],input[j++]);
        
        while(!isdigit(input[j])){
            if(i < numberOfLists-1){
                // Skipping the 'Blank Spaces, by Taylor Swift' ;)
                if(input[j] != ' ')
                    pushFront(&operators[i], input[j]);        
            }
            j++;
        }

        // displayList(l[i]);
        // displayList(operators[i]);
    }

    
    Infix infix;
    initInfixList(&infix, numberOfLists *2 - 1);
    for(int i = 0; i < numberOfLists; i++){
        createInfix(&infix,l[i]);
        if( i < numberOfLists - 1)
            createInfix(&infix,operators[i]);
    }

    displayInfix(infix);

    

    
    StackOfList s;
    initStackOfList(&s,numberOfLists * 2 - 1 );
    printf("%d\n",s.size);
    for( int i = 0; i < s.size; i++){
        pushToStackOfList(&s,l[i]);
        if( i < numberOfLists - 1)
            pushToStackOfList(&s, operators[i]);
    }

    // for( int i = 0; i < s.size; i++){
    //     displayList(popFromStackOfList(&s));
    // }

}