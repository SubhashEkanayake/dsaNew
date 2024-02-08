#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXQUEUE 20
#define TRUE 1
#define FALSE 0

typedef int dqElement;

typedef struct dqueue{
    dqElement items[MAXQUEUE];
    int front;
    int rear;
    int count;
}Dqueue;

void createQueue(Dqueue *q){
    q->front = -1;
    q->rear = -1;
    q->count = 0;
    printf("dqueue is created\n");
}

int isQueueEmpty(Dqueue *q){
    if((q->front = -1) && (q->rear = -1)){
        printf("Dqueue is empty\n)");
    }
    return TRUE;
}


int isQueueFull(Dqueue *q){
    if(q->count == MAXQUEUE){
        printf("Dqueue is full\n");
    }    
    return FALSE;
}


void AppendFront(dqElement x,Dqueue *q){
    if(!isQueueFull(q)){
        if(q->front == 0){
            q->front = MAXQUEUE -1;
            q->items[q->front] = x;
            printf("🛑Appended front item %d\n",x);
        }else if(q->front == -1 && q->rear == -1){
            q->front = q->rear = 0;
            q->items[q->front] = x;
            printf("🛑Appended front item %d\n",x);
        }else{
            q->front = q->front -1;
            q->items[q->front] = x;
            printf("🛑Appended front item %d\n",x);
        }
    }else{
        isQueueFull(q);
    }
}


void AppendRear(dqElement x,Dqueue *q){
    if(!isQueueFull(q)){
        if(q->front ==-1 && q->rear ==-1){
            q->front = q->rear = 0;
            q->items[q->rear] = x;
            printf("🛑Appended rear item %d\n",x);
        }else if(q->rear == MAXQUEUE -1){
            q->rear = (q->rear+1)%MAXQUEUE;
            q->items[q->rear] = x;
            printf("🛑Appended rear item %d\n",x);
        }else{
            q->rear = q->rear +1;
            q->items[q->rear] = x;
            printf("🛑Appended rear item %d\n",x);
        }
    }else{
        isQueueFull(q);
    }
}


void DeleteFront(Dqueue *q){
    if(!isQueueEmpty(q)){
        if(q->front == q->rear){
            int x = q->items[q->front];
            q->front =q->rear = -1;
            printf("🛑DeleteFront item %d\n",x);
        }else if(q->front == MAXQUEUE -1){
            int x = q->items[q->front];
            printf("🛑DeleteFront item %d\n",x);
            q->front = (q->front+1)%MAXQUEUE;
        }else{
            int x = q->items[q->front];
            printf("🛑DeleteFront item %d\n",x);
            q->front = q->front + 1;
        }
    }else{
        isQueueEmpty(q);
    }
}


void DeleteRear(Dqueue *q){
    if(!isQueueEmpty(q)){
        if(q->front == q->rear){
            int x = q->items[q->front];
            q->front =q->rear = -1;
            printf("🛑DeleteRear item %d\n",x);
        }else if(q->rear == 0){
            int x = q->items[q->rear];
            printf("🛑DeleteRear item %d\n",x);
            q->rear = MAXQUEUE -1;
        }else{
            int x = q->items[q->rear];
            printf("🛑DeleteRear item %d\n",x);
            q->rear =   q->rear -1;
        }
    }else{
        isQueueEmpty(q);
    }
}


int main(){
    Dqueue dq;
    createQueue(&dq);

    AppendFront(10,&dq);
    AppendFront(20,&dq);
    AppendFront(30,&dq);
    AppendRear(50,&dq);
    AppendRear(60,&dq);
    DeleteRear(&dq);
    DeleteFront(&dq);
    DeleteFront(&dq);







    return 0;
}