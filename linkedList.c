#include "linkedList.h"

void initList(List *l){
    *l = NULL;
return;
}

Node* createNewNode(char data){
    Node * nn = (Node*) malloc(sizeof(Node));
    nn -> data = data;
    nn -> next = NULL;
    return nn;
}

void pushFront(List * l, char data){
    if(*l == NULL){
        if(isdigit(data)){
            *l = createNewNode('1'); // initializing to positive
            (*l)->next = createNewNode(data);
        }else
            *l = createNewNode(data);
        return;
    }

    Node * nn = createNewNode(data);
    nn->next = *l;
    *l = nn;
return;
}

char popFront(List * l){
    if(isEmpty(*l))
        return '\0';
    Node * temp = *l;
    char data = temp -> data;
    *l = (*l)->next;
    free(temp);
    return data;
}


int isEmpty(List l){
    if(l == NULL)
        return true;
    return false;
}

void displayList(List l){
    
    if(l == NULL)
        return;
    Node *p = l;
    while(p){
        printf("%c",p -> data);
        if(p->next)
            printf(" -> ");
        p = p -> next;
    }
    printf("\n");
return;
}

void displayNumber(List l){
    if(l == NULL)
        return;
        displayNumber(l->next);
        printf("%c", l->data);
return;
}

void reverseList(List *l){
    Node * current = *l;
    Node * previous = NULL;
    Node * next = NULL;

    while( current != NULL){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *l = previous;

}