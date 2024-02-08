#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 20
#define TRUE 1
#define FALSE 0


//defining queue
typedef int queueElement;

typedef struct queue{
    queueElement items[MAX];
    int front;
    int rear;
    int count;
}Queue;

//create queue
void createQueue(Queue *q){
    q->count = 0;
    q->front = 0;
    q->rear = -1;
    printf("-->Q is created\n");
}

int isQueueEmpty(Queue *q){
    return (q->count == 0);
}

int isQueueFull(Queue *q){
    return (q->count == MAX-1);
}

void Append(queueElement x,Queue *q){
    if(isQueueEmpty(q)){
        q->front = q->rear = 0;
        q->items[q->rear] = x;
        printf("🛑Appended item %d\n",x);
        q->count++;
    }else if(isQueueFull(q)){
        printf("-->Q is full\n");
    }else{
        q->rear = (q->rear+1)%MAX;
        q->items[q->rear] = x;
        q->count++;
        printf("🛑Appended item %d\n",x);
    }
}


void Serve(Queue *q){
    if(isQueueEmpty(q)){
        printf("-->Q is empty\n");
    }else{
        int x = q->items[q->front];
        q->front = (q->front+1)%MAX;
        printf("🛑Served item %d\n",x);
        q->count--;
    }
}

void displayElements(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("-->Q is empty\n");
    } else {
        int i = q->front;
        int count = 0;

        printf("Queue Elements:\n");

        while (count < q->count) {
            printf("element %d: %d\n", count + 1, q->items[i]);
            i = (i + 1) % MAX;
            count++;
        }
    }
}

int main(){
    Queue queue;

    createQueue(&queue);

    Append(100,&queue);
    Append(200,&queue);
    Append(300,&queue);
    Append(400,&queue);
    Append(500,&queue);
    Append(600,&queue);
    Serve(&queue);
    displayElements(&queue);
    



    return 0;
}