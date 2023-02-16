#include<stdio.h>
#include "linkedList.h"

int getSize(char * str){
    int size = 0;
    while(str[size] != '\0')
        size++;
    return size;
}

int main(){
    List l;
    initList(&l);
    char input[100];
    scanf("%s",input);

    int size = getSize(input);
    for(int i = 0; i < size ;i++){
        pushFront(&l,input[i]);
    }

    displayList(l);
    displayNumber(l);
    printf("\n");
        
}