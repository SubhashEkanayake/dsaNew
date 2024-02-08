#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef int stackEntry;

//Structure of a node
typedef struct node{  
    stackEntry entry; //value of node
    struct node *next; //pointer of next node
}Node;


//Defining the stack
typedef enum{FALSE,TRUE}Boolean;

typedef struct{
    int no_ele; //no of elements inthe stack
    Boolean full; //whether stack is full or not
    Node *top; //to point the top element of stack
}Stack;

//create stack
void createStack(Stack *s){
    s->top = NULL; //Initially top shoul be null
    s->no_ele = 0; //no elements initially
    s->full = FALSE; //initially stack is empty
    printf("-->Stack is created\n");
}

//Is stack empty
Boolean isStackEmpty(Stack *s){
    return (s->top == NULL);  /*it checks whether top pointer is null,
    if it is null return true,otherwise return false */
}

Boolean isStackFull(Stack *s){
    return (!(s->full));  //if stack is full,return true,otherwise false
}


void push(stackEntry item,Stack *s){
    Node *np; //hold the address of new element to be pushed into the stack
    np = (Node *)malloc(sizeof(Node)); //get memory address after type casted into Node

    if(np == NULL){ //it checks Heap memory is null?
        printf("Not enough memory");
        s->full = TRUE; //memory is already full
    }else{
        np ->entry = item; //pushed item assign to the node 
        np ->next = s->top; //top value assign to the node pointer
        s->top = np; //currently np address assign to top
        s->no_ele++;
        printf("🛑item %d pushed into the stack\n",item);
    }
}

void pop(Stack *s){
    Node *np; //declare pointer variable
    int item = s->top->entry; //latest added item assign to item pointer
    printf("🛑Popped item = %d\n",item);
    np = s->top; //currently top address assign to np
    s->top = s->top->next; //addres of dropped node assin to new top
    s->no_ele--; 
    free(np); //deallocate np
}


void destroyStack(Stack *s){
    printf("-->Stack is destroyed\n");
    free(s);
}


int main(){
    Stack stack;
    createStack(&stack);

    push(100,&stack);
    push(200,&stack);
    push(300,&stack);
    push(400,&stack);
    push(500,&stack);
    pop(&stack);
    
    return 0;
}
