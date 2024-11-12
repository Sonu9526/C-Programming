#include<stdio.h>
#include<stdlib.h>
int main(){
   int a;
   int *p; //p is now a pointer variable that points to an interger 
   p=&a; //if we put a '&' n front of a variable it gives the address of tha particular variable
   a=5;
   printf("%p\n",p); // it give the memory adddres of a
   printf("%p\n",&p); // it give the memory addres of p
   printf("%p\n",*p); // if we put '*' in front of pointer  then it gives the value at the locationthat points to
        // this concept is known as e-referencing becaues we have a reference we can get the value at this particular addres using the operator 
        *p =10;
        printf("%d",a);   
    return 0;
} 