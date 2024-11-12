#include<stdio.h>
#include<stdlib.h>
int main(){
    struct node {
        int data;
        struct node * next;
    };

    struct node * newNode, *current , *start=NULL;
     int i,n;
     printf("Enter the number of nodes :");
     scanf("%d",&n);
     printf("Enter the Values in Linked list: ");

    //  creation of Linked List
      for(i=1;i<=n;i++)
      {
        newNode=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&newNode->data);
        newNode->next=NULL;
        if(start == NULL)
        {
            start =newNode;
            current=newNode;
        }else
        {
            current->next=newNode;
            current=newNode;
        }
      }

    //   traversal of Linked list
      printf("\n The Linked List \n");
      for(current=start;current!=NULL;current=current->next)
      {
        printf("%d->",current->data);
      }
      printf("NULL");

}
