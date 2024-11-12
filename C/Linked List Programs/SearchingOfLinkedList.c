
// Error in this code !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include<stdio.h>
#include<stdlib.h>
int main(){
    struct node {
        int data;
        struct node * next;
    };

    struct node * newNode, *current , *start=NULL;
     int i,n,pos,item,flag=0;
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

    // Searching of Linked List
    printf("\nEnter the value you want to search :\n");
    scanf("%d",&item);
    for(current=start,pos=1;current!=NULL;current->next,pos++)
    {
        if(current->data==item)
        {
            printf("Item found at position %d",pos);
            flag=1;
            break;
        }
        if(flag==0)
        {
            printf("Item is not in this Linked list");
            break;
        }
    }
        
        
    }



