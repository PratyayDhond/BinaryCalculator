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
            // displayList(ans);
            reverseList(&ans->next);
            // displayList(ans);
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
    List temp;

    Node *p = l2 -> next;
    int count = 0;
    while(p){
    initList(&temp);
        int n = p -> data - '0';
            // printf("\n%d\n",n);
        for(int i = 0; i < n; i++){
            temp =  add(temp,l1);
            // displayList(temp);
        }

        // printf("-----------------------------------------------------");
        for(int i = 0; i < count; i++)
            pushFront(&temp,'0');
        count++;

        ans = add(ans,temp);
        // printf("%d\n",n);
        // displayList(ans);
        // printf("\n");
        // displayNumber(ans);
        // printf("\n");
        p = p->next;
    }

    if( l1 -> data != l2->data)
        ans -> data = ans -> data == '1' ? '0' : '1';
    return ans;

}

Node * divide(List l1, List l2){
    
}

void initTemp(List* temp,List l1){
    initList(temp);
    Node *q = l1->next;
    while(q){
        pushFront(temp,q->data);
        q = q->next;
    }
    reverseList(temp);
return;
}


Node * toThePower(List l1, List l2){
    return NULL;
}

// Node * toThePower(List l1, List l2){
//     List result;
//     initList(&result);
//     Node *p = l2->next;
//     int n; List temp;
//     int count = 0;

//     initTemp(&temp,l1);

//     while(p){

//         n = p->data - '0';

//         if(n * (count* 10) == 0 && n != 0)
//             n = n;
//         else
//             n = n * (count* 10);
        
//         for(int i = 1; i < n; i++){
//             temp = multiply(temp,l1);
//         }

//         // for(int i = 0; i < count; i++)
//             // pushFront(&temp,'0');
//         displayList(temp);
//         displayList(result);
//         printf("\n\n\n");
//         if(n == 0)
//             result = add(result,NULL);
//         else
//             result = add(result,temp);
//         count++;
//         p = p -> next;  

//         initTemp(&temp,l1);
//     }
//     reverseList(&result);
//     reverseList(&result->next);
//     displayList(result);
//     return result;

// }

Node * mod(List l1, List l2){

}

