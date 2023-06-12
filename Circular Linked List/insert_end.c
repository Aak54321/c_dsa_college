#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*start,*newnode,*ptr;
void create(int dt){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=dt;
    if(start == NULL){
        start=ptr=newnode;
    }
    else{
        ptr->next=newnode;
        ptr=newnode;
    }
    newnode->next=start;
}
void display(){
    if(start ==  NULL){
        printf("list is empty");
    }
    else{
        ptr=start;
    while(ptr->next!=start){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
    }
}
void insert_end(){
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter data for node to be inserted at end:");
    scanf("%d",&newnode->data);
    ptr=start;
    while(ptr->next!=start)
        ptr=ptr->next;
    ptr->next=newnode;
    newnode->next=start;
}
void main(){
    int n,dt;
    printf("Enter no. of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter data:");
        scanf("%d",&dt);
        create(dt);
    }
    printf("list before insertion\n");
    display();
    insert_end();
    printf("\nlist after insertion\n");
    display();
}