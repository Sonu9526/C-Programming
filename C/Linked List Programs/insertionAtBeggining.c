#include<stdio.h>
#include<stdlib.h>
int main(){
    struct node {
        int data;
        struct node * next;
    };

    struct node * newNode, *current , *start=NULL;
     int i,n,item;
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

    

    // Insertion At Beggining

    printf("\nEnter the value you want to insert: \n");
    scanf("%d",&item);
    newNode->data=item;
    if(start == NULL){
        start = newNode;
        start->next=NULL;
    }else{
        newNode->next=start;
        start=newNode;
    }


    //   traversal of Linked list
    

    void display(){
        printf("\n The Linked List \n");
      for(current=start;current!=NULL;current=current->next)
      {
        printf("%d->",current->data);
      }
      printf("NULL");
      };
}
