#include "binaryCalculator.h"

int scale = 0;
List ans;

void setScale(int n){
    scale = n;
}

int isZero(List l){
    Node *p = l;
    while(p){
        if( p -> data != '0')
            return false;
        p = p -> next;
    }
    return true;
}

Node * add(List l1, List l2){

}

Node * subtract(List l1, List l2){

}

Node * multiply(List l1, List l2){
    initList(&ans);
    List subtractOne;
    initList(&subtractOne);
    pushFront(&subtractOne,'1');

    Node * p = l1;
    while(p){
        pushFront(&ans, p->data);
        p = p -> next;
    }
    reverseList(&ans);
    subtract(l2,subtractOne);

    while(!isZero(l2)){
        ans = add(ans,l1);
        l2 = subtract(l2,subtractOne);
    }

    return ans;

}

Node * divide(List l1, List l2){

}

Node * toThePower(List l1, List l2){
    initList(&ans);
    if(isZero(l2)){
        pushFront(&ans, '1');
        return ans;
    }
    List temp,temprev;
    initList(&temp);

    Node *p = l1;
    while(p){
        pushFront(&temp, p->data);
        p = p -> next;
    }
    reverseList(&temp);


    // printf("\n");
    // displayList(l1);
    // printf("l1\n");
    // displayList(l2);
    // printf("l2\n");
    // displayList(temp);
    // printf("temp\n");
    List subtractOne;
    initList(&subtractOne);
    pushFront(&subtractOne,'1');

    while(!isZero(l2)){
        ans = multiply(l1,temp);
        l2 = subtract(l2,subtractOne);
    }

    return ans;   

}

Node * mod(List l1, List l2){

}

