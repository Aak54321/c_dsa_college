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
void del_beg(){
    ptr=start;
    while(ptr->next!=start){
        ptr=ptr->next;
    }
    ptr->next=start->next;
    free(start);
    start=ptr->next;
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
    printf("list before deletion\n");
    display();
    del_beg();
    printf("\nlist after deletion\n");
    display();
}