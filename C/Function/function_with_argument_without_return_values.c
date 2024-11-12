#include<stdio.h>
#include<stdlib.h>
void sum (int , int); //function declaration
int main(){
    int num1,num2;
    printf("Enter two number :");
    scanf("%d %d",&num1,&num2);
    sum(num1,num2); //function calling
    return 0;
}
void sum(int number1,int num2){
      //function defenition
    int sum;
    sum=number1+num2;
    printf("The sum of two number is %d",sum);
};
