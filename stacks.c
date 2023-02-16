#include "stacks.h"

void initStackOfList(StackOfList *s, int size){
    s -> size = size;
    s -> arr = (List *) malloc(sizeof(List *) * size);
    s -> top = -1;
return;
}

void pushToStackOfList(StackOfList *s, List l){

    // if(s->top == NULL){
    //     s->top[] = l;
    //     s->count++;
    //     return;
    // }
    if( s->top < s->size - 1)
        s->arr[++s->top] = l;
    
return;
}

List popFromStackOfList(StackOfList *s){
    if(s == NULL)   
        return NULL;

    if(s->top == -1)  
        return NULL;

    return s->arr[s->top--];    
}

int isEmptyStackOfList(StackOfList s){
    return s.top == -1 ? true : false;
}
