#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *front,*rear,*newnode,*ptr;

void enqueue(int dt){
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=dt;
    newnode->next=NULL;
    if(newnode == NULL){
        printf("\nOverflow");
    }
    if(front == NULL){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue(){
    if(front == NULL){
        printf("\nUnderflow\n");
    }
    else{
        ptr=front;
        printf("\n%d is Dequeued from the Queue\n",front->data);
        front=front->next;
        free(ptr);
    }
}
void display(){
if(front == NULL){
    printf("\nEmpty Queue\n");
}
else{
 ptr=front;
 printf("Contents of the queue:");
 while(ptr!= NULL){
    printf("%d ",ptr->data);
    ptr=ptr->next;
 }
 printf("\n");
 }   
}
void main(){
    int choice,dt;
    printf("************MAIN MENU***********\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    do{
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter data:");
                scanf("%d",&dt);
                enqueue(dt);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
        }
    }while(choice != 4);
}