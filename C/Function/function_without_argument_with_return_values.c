#include<stdio.h>
#include<stdlib.h>
int sum();
int main(){
    int result =sum();
    printf("The sum of two number is %d",result);
    return 0;
}
int sum(){
    int num1,num2;
    printf("Enter two values :");
    scanf("%d%d",&num1,&num2);
    return num1+num2;
} 