#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//defining a node

typedef int queueElement;

typedef struct node{
    queueElement entry; //node value
    struct node *next; //node address
}queueNode;

typedef enum{FALSE,TRUE}Boolean;

//defining queue

typedef struct {
    queueNode *head;
    queueNode *tail;
    int count;
    Boolean full;
}Queue;

//createQueue
void createQueue(Queue *q){
    q->head = NULL;
    q->tail = NULL;
    q->full = FALSE;
    printf("-->Q is created\n");
}

//isQueueEmpty
Boolean isQueueEmpty(Queue *q){
    return (q->head == NULL && q->tail == NULL);
}

Boolean isQueueFull(Queue *q){
    return (q->full = TRUE);
}

void Append(queueElement x,Queue *q){
    queueNode *newNode;
    newNode = (queueNode *)malloc(sizeof(queueNode));

    if(newNode == NULL){
        printf("-->Not enough memory");
        exit(1);
    }else{
        newNode->entry = x;
        newNode->next = NULL;

        if(isQueueEmpty(q)){
            q->head = q->tail = newNode;
            printf("🛑Appended element %d\n",x);
        }else{
            q->tail->next = newNode;
            printf("🛑Appended element %d\n",x);
        }
        q->count++;
    }
}

void Serve(Queue *q){
    queueNode *np;

    if(!isQueueEmpty(q)){
        int pop = q->head->entry;
        printf("🛑Popped item %d\n",pop);
        np = q->head;
        q->head = q->head->next;
        q->count--;
        free(np);

    }
}

void Peek(Queue *q) {
    if (!isQueueEmpty(q)) {
        int peekEl =  q->head->entry;
        printf("Peek element is: %d\n",peekEl);
    } else {
        printf("-->Queue is empty\n");
    }
}



int main(){
    Queue queue;

    createQueue(&queue);
    Append(100,&queue);
    Append(200,&queue);
    Append(300,&queue);
    
    Serve(&queue);
    Peek(&queue);





    return 0;
}