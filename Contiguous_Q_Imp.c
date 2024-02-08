#include<stdio.h>
#include<stdlib.h>

#define MAX 10
#define TRUE 1
#define FALSE 0

typedef int queueElement;

//definition of queue
typedef struct {
    queueElement items[MAX]; //to hold elements
    int front; //first element
    int rear; //last element
    int count; //count elements
}Queue;

//createQueue
void createQueue(Queue *q){
    q->count = 0; //
    q->front = 0;
    q->rear = -1;
    printf("-->Q is created\n");
}

//IsQueueEmpty
int isQueueEmpty(Queue *q){
    if(q->rear < q->front){
        printf("-->Q is empty\n");
        return TRUE;
    }else{
        printf("-->Q is not empty\n");
        return FALSE;
    }
}


//IsQueueFull
int isQueueFull(Queue *q){
    if(q->rear == MAX -1){
        printf("-->Q is Full\n");
        return TRUE;
    }else{
        printf("-->Q is not full\n");
        return FALSE;
    }
}


//Add elements

void Append(int item,Queue *q){
    if(!isQueueFull(q)){
        q->items[(++q->rear)] = item;
        printf("🛑Appended element %d\n",item);
        q->count++;
        printf("-->Count =%d\n",q->count);
    }else{
        printf("-->Q is full\n");
        exit(1);
    }
}


//Remove elements
void Remove(Queue *q){
    if(!isQueueEmpty(q)){
        int popped = q->items[q->front];
        printf("🛑Popped element: %d\n",popped);
        q->front++;
        q->count--;
    }else{
        printf("-->Q is empty\n");
    }
}


void Peek(Queue *q){
    if(!isQueueEmpty(q)){
        int peekEl = q->items[q->front];
        printf("🛑Peek element:%d\n",peekEl);
    }
}


void Display(Queue *q){  //not finalized
    if(!isQueueEmpty(q)){
        printf("-->All elements:\n");
        for(int i=0;i<MAX;i++){
            printf("\t👉element %d: %d \n",q->count,q->items[q->count]);
        }
    }
}
int main(){
    Queue queue;
    createQueue(&queue);

    Append(10,&queue);
    Append(20,&queue);
    Append(30,&queue);
    Append(40,&queue);
    Remove(&queue);
    Remove(&queue);
    Peek(&queue);




    return 0;
}

