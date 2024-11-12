#include<stdio.h>
#include<stdlib.h>
void sum();  //function declaration
int main(){
    sum();  //function calling
    return 0;
}
void sum(){  //function defenition
        int num1,num2,sum;
        printf("Enter two numbers:");
        scanf("%d%d",&num1,&num2);
        sum=num1+num2;
        printf("Sum of two numbers is:%d",sum);
    };