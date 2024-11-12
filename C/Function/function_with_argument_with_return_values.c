#include<stdio.h>
#include<stdlib.h>
int sum (int , int); //function declaration
int main(){
    int num1,num2;
    printf("Enter two number :");
    scanf("%d %d",&num1,&num2);
  int result =  sum(num1,num2); //function calling
  printf("The sum of two number is %d",result);
    return 0;
}
int sum(int number1,int num2){
      //function defenition
    int sum;
    return sum=number1+num2;
};
