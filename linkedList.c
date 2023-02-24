#include "linkedList.h"

void initList(List *l){
    *l = NULL;
return;
}

void destroyList(Node * l){
    // if(*l == NULL)
        // return;
    // Node *p = *l;
    // if(p -> next == NULL){
        // free(p);
        // return;
    // }    
    // Node * temp;
        // temp = p;
        // p = p -> next;
        // printf("%c %p\n", p->data, p->next);
    // }
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
            pushFront(l,data);
            // (*l)->next = createNewNode(data);
            return;
        }
            *l = createNewNode(data);

        return;
    }
    Node * p = *l;
    Node * nn = createNewNode(data);
    nn->next = p -> next;
    p->next = nn;
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

void displayInReverse(List l){
    if(l == NULL)
            return;
            displayInReverse(l->next);
            printf("%c", l->data);
    return;
}

void displayNumber(List l){
// checking if the list is empty
    if(l == NULL)
        return;
    else
// checking if the list's next is empty which implies that the list is an operator
        if(l ->next == NULL)
            displayInReverse(l);
        else{
// checking if the list's next is not empty it means that it is and operand, so we skip the first bit which is the sign bit
            if(l->data == '0')
                printf("-");
            displayInReverse(l->next);
        }
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