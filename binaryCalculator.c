#include "binaryCalculator.h"
#define POSITIVE 1
#define NEGATIVE 0


int scale = 0;
List ans;

void setScale(int n){
    scale = n;
}

int fetchSign(List l){
    Node * p = l;
    while(p->next)
        p = p -> next;
    if(p->data == '1')
        return POSITIVE;
    else 
        return NEGATIVE;
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

void comp(List l1, List l2, int * greater){
    if(l1 == NULL)
        return;
        comp(l1->next,l2->next,greater);
        if(*greater == 0)
            if(l1->data > l2->data)
                *greater = 1;
            else if( l2->data > l1 -> data)
                *greater = -1;
}

int compareNumbers(List l1,List l2){
    int greater = 0;
    comp(l1->next,l2->next,&greater);
    return greater;
}

Node * add(List l1, List l2){
    if(l1 == NULL && l2 == NULL)
        return NULL;
    
    if(l1 == NULL)
        return l2;
    else if( l2 == NULL)
        return l1;

    if(l1->next == NULL && l2->next == NULL)
        return NULL;
    
    if(l1->next == NULL)
        return l2;
    else if( l2->next == NULL)
        return l1;    

    List ans;
    initList(&ans);

    Node *p = l1->next;
    Node *q = l2->next;
    int carry = 0,a,b;
    
    while(p && q){
        a = p->data - '0';
        b = q->data - '0';
        pushFront(&ans, ((a + b + carry) % 10) + '0');
        if(a+b+carry > 9)
            carry = 1;
        else
            carry = 0;

        p = p -> next;
        q = q -> next;
    }

    while(p){
        a = p -> data - '0';
        pushFront(&ans, ((a + carry) % 10) + '0');
        if( a + carry > 9)
            carry = 1;
        else
            carry = 0;
        p = p -> next;
    }

    while(q){
        a = q -> data - '0';

        pushFront(&ans, ((a + carry) % 10) + '0');
        if( a + carry > 9)
            carry = 1;
        else
            carry = 0;
            
        q = q -> next;
    }
     q = ans -> next;
    if(carry == 1)
        pushFront(&ans,carry + '0');

// alternative but O(n) approach for appending the carry
    // while(carry == 1){
    //     a = q -> data - '0';
    //     pushFront(&ans, ((a + carry) % 10) + '0');
    //     if(a + carry > 9)
    //         carry = 1;
    //     else 
    //         carry = 0;
    // }

    reverseList(&ans->next);

    return ans;
}

Node * subtract(List l1, List l2){
    if(l1 == NULL && l2 == NULL)
        return NULL;
    else if(l1 == NULL)
        return l2;
    else if(l2 == NULL)
        return l1;
    
    List ans;
    initList(&ans);

    Node *p = l1->next;
    Node *q = l2->next;
    char signL1 = l1 -> data == '1' ? '+' : '-';
    char signL2 = l2 -> data == '1' ? '+' : '-';
    int borrow = 0,a,b,current;

    int lengthComp;

    while(p && q){
        p = p -> next;
        q = q -> next;
    }
    if(p)
        lengthComp = 1;
    else if(q)
        lengthComp = -1;
    else 
        lengthComp = 0;

    p = l1->next;
    q = l2->next;
    // If the first number is greater than the second number
    if(lengthComp == 1){
        while(p && q){
            a = p->data - '0';
            b = q->data - '0';

            // result of the current two digit's subtraction
            current = (a - b - borrow);
              if(a-b-borrow < 0)
                borrow = 1;
            else
                borrow = 0;
            if(borrow == 1)
                current += 10;

            pushFront(&ans, (current) + '0');
            printf("%d %d %d %c\n",a,b,borrow,current + '0');

            p = p -> next;
            q = q -> next;            
        }
        while(p){
            a = p -> data - '0';
            pushFront(&ans, ((a - borrow)) + '0');
            if( a - borrow < 0)
                borrow = 1;
            else
                borrow = 0;
            p = p -> next;
        }
        // reversing the list except the sign bit
        reverseList(&ans -> next);
        return ans;    
    }else if(lengthComp == -1){
        ans = subtract(l2,l1);
        if(ans->data == '1')
            ans ->data = '0';
        else
            ans -> data = '1';
        return ans;
    }else{
        // l1 > l2 when compareNumbers returns 1
        if(compareNumbers(l1,l2) == 1){
            while(p && q){
                a = p->data - '0';
                b = q->data - '0';

                // result of the current two digit's subtraction
                current = (a - b - borrow);
                  if(a-b-borrow < 0)
                    borrow = 1;
                else
                    borrow = 0;
                if(borrow == 1)
                    current += 10;

                pushFront(&ans, (current) + '0');
                printf("%d %d %d %c\n",a,b,borrow,current + '0');

                p = p -> next;
                q = q -> next;            
            }
            displayList(ans);
            reverseList(&ans->next);
            displayList(ans);
            return ans;
        }else{
            ans = subtract(l2,l1);
            ans -> data = ans -> data == '1' ? '0' : '1';
            return ans;
        }

    }
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

