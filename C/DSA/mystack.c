#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top=-1,stack[MAX];

int isFull(){
return top == MAX-1;
}

int  isEmpty(){
    return top ==-1;
}

void push(){
    if(isFull()){
        printf("Stack is full");
    }else{
        int value;
        printf("Enter the value you want to push:");
        scanf("%d",&value);
        top++;
    stack[top]=value;
    printf("%d is pushed to the stack",value);
    }
}

void pop (){
    int poppedValue=stack[top];
    top--;
    printf("%d is popped out from the stack",poppedValue);
}

void display(){
    for(int i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
}

 int  main(){
    int choice;
    while (1){
       printf("\nStack Operations:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        push();
            break;

        case 2:
        pop();
        break;

        case 3:
        display();
        break;
        case 4:
        return 0;
        break;

        default:
        printf("please choose a valid option");
            break;
        }
    }
}