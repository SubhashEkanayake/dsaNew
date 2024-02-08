#include <stdio.h>
#include<stdlib.h>



typedef enum {FALSE, TRUE} Boolean;

typedef int ListData;
typedef int Position;

typedef struct listnode {
    ListData lData;
    struct listnode *next;
}ListNode;

typedef struct {
    int count; Boolean full; ListNode
    *head;
}List;

void CreateList(List *l){
    l->count = 0;
    l->head = NULL;
    l->full = FALSE;
    printf("List is created\n");
}

Boolean IsListEmpty(const List *l){
    return (l->head == NULL);
}

Boolean IsListFull(const List *l){
return (l->full);
}


int ListSize (const List *l){
    return (l->count);
}

ListNode * MakeListNode (ListData x){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    if (p){
        p -> lData = x;
        p -> next = NULL;
    }
    return (p);
}


void SetPosition(Position p, List *l, ListNode **current){
    int count; //used to travel through positions
    ListNode *q; //used to travel list
    if (p<0 || p> l->count)
    printf("Attempt to set a position not in the list");
    else {
    //count from head of list to position p
    q = l->head;
    for (count = 1; count <=p; count++)
    q = q->next;
    *current = q;
    }
}

void InsertList (Position p, ListData x, List *l){
    ListNode *newnode=NULL, 
    *current=NULL;
    if (p < 0 || p > ListSize(l)){
        printf("attempt to insert a position not in the list");
    }
    else{
        newnode = MakeListNode(x);
        if (newnode == NULL){
            l->full = TRUE;
            printf("Not enough memory for additional node");
        }
        else{
            if (p==0){           //Insert as the first element
                newnode->next = l->head;
                l->head =newnode;
            }
            else{
                SetPosition(p-1, l, &current);
                newnode->next = current->next;
                current->next = newnode;
            }
            l->count++;
        }
    }
}

int main(){
    List l;
    CreateList(&l);
    InsertList(0,333,&l);




    return 0;
}


