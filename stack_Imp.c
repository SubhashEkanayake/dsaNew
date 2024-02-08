#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAXSTACK 5 
#define TRUE 1
#define FALSE 0  //execute successfully

typedef int stackEntry;

typedef struct {
    int top ;
    stackEntry entry[MAXSTACK];
}Stack;

void createStack(Stack *s){
    s->top = -1;
    printf("-->Top = %d\n",s->top);
    printf("-->Stack is created\n\n\n");
}

int isStackFull(Stack *s){
    if(s->top == (MAXSTACK-1)){
        printf("-->Stack is full\n");
        return TRUE;
    }else{
        printf("-->Stack is not full\n");
        return FALSE;
    }
}

int isStackEmpty(Stack *s){
    if (s->top == -1){
        printf("-->stack is empty\n");
        return TRUE;
    }else{
        printf("-->stack is not empty\n");
        return FALSE;
    } 
}

void push(stackEntry item, Stack *s){
    if(!isStackFull(s)){
        s->entry[++s->top]= item;
        printf("🛑Item %d pushed into stack & top=%d\n",item,s->top);
    }else{
        printf("-->Stack is full\n");
    }
}

void pop(Stack *s){
    if(!isStackEmpty(s)){
        int item = s->entry[s->top];
        s->top--;
        printf("🛑Popped item : %d & top=%d\n",item,s->top);
    }else{
        printf("-->Stack is empty\n");
        exit(1);
    }
}


void display(Stack *s){
    if(isStackEmpty(s)){
        printf("-->Stack is empty");
    }else{
        printf("-->Here are items:\n");
        for(int i=0;i<=MAXSTACK;i++){
            if(i == (s->top+1)){
                break;
            }
        printf("\t👉entry[%d] = %d\n",i,s->entry[i]);
    }
    }
}

void peek(Stack *s){
    int peekEle = s->entry[s->top];
    printf("Peek element is: %d\n",peekEle);
}

int main(){
    Stack stack;
    createStack(&stack);
    
    push(10,&stack);
    push(50,&stack);
    push(70,&stack);
    push(90,&stack);
    display(&stack);
    peek(&stack);
    

   
    return 0;
}


