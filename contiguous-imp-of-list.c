#include<stdio.h>
#include<stdlib.h>

#define MAXLIST 10
#define EMPTY 0
#define FULL MAXLIST

typedef enum {FALSE, TRUE} Boolean;

typedef int ListData;
typedef int Position;

typedef struct{
    int count;
    ListData entry[MAXLIST];
} List;

void createList(List *l)
{
    l->count = 0;
    printf("List is created..\n");
}

Boolean isListEmpty(List *l)
{
    if(l->count == EMPTY) return TRUE;
    
    return FALSE;
}

Boolean isListFull(List *l)
{
    if(l->count == FULL) return TRUE;
    
    return FALSE;
}

int listSize(List *l)
{
    return l->count;
}

void insertLast(List *l, ListData x)
{
    if(isListFull(l)) {
        printf("List is full");
        exit(1);
    }
    
    l->entry[l->count++] = x;
}

void insertList(Position p, List *l, ListData x)
{
    if(isListFull(l))
    {
        printf("List is full");
        exit(1);
    }
    
    for(int i = listSize(l) - 1; i >= p; i--)
    {
        l->entry[i+1] = l->entry[i];
    }
    l->count++;
    l->entry[p] = x;
    printf("Inserted item %d\n",x);
}

void deleteList(Position p, List *l, ListData *x){
    if(isListEmpty(l))
    {
        printf("List is Empty");
        exit(1);
    }
    
    *x = l->entry[p];
    printf("deleted item\n");
    for(int i = p; i < listSize(l); i++){
        l->entry[i] = l->entry[i+1];
    }
    l->count--;
}


void retrieveList(List *l, ListData *x, Position p)
{
    if(isListEmpty(l))
    {
        printf("List is Empty");
        exit(1);
    }
    
    if(p < 0 && listSize(l) <= p)
    {
        printf("Invalid position");
        exit(1);
    }
    *x = l->entry[p];
    printf("Retrieved item %d\n",l->entry[p]);
}


void replaceList(List *l, Position p, ListData x)
{
    if(isListEmpty(l))
    {
        printf("List is Empty");
        exit(1);
    }
    
    if(p < 0 && listSize(l) <= p)
    {
        printf("Invalid position");
        exit(1);
    }
    
    l->entry[p] = x;
    printf("Replaced position %d by %d\n",p,x);
}

void printList(List *l)
{
    for(int i = 0; i < l->count; i++)
    {
        printf("%d ", l->entry[i]);
    }
    printf("\n");
}

int main()
{
    List l;
    createList(&l);
    insertList(0,&l,10);
    insertList(1,&l,20);
    insertList(2,&l,30);
    replaceList(&l,1,3000);
    //deleteList(1,&l,);
    printList(&l);

    ListData deletedItem;
    //deleteList(1, &l, &deletedItem);

    insertList(3,&l,40);
    insertList(4,&l,50);
    insertList(5,&l,60);

    //deleteList(2,&l,&deletedItem);


    ListData retrieveData;
    retrieveList(&l,&retrieveData,3);

    printList(&l);

    retrieveList(&l,&retrieveData,5);

}