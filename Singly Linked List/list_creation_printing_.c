#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start,*newnode,*ptr;
void addNode(int dt){
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=dt;
    newnode->next=NULL;
    if(start == NULL){
        start=ptr=newnode;
    }
    else{
        ptr->next=newnode;
        ptr=newnode;/*👈 because newnode will be changed afterwards,so ptr is updated here*/
    }
}
void display(){
    if(start == NULL){
        printf("NULL");
    }
    else{
    ptr=start;
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    if(ptr == NULL){
        printf("NULL");
    }
}
}
void main(){
    int n,dt;
    printf("Enter no. of elements in list:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("Enter element:");
        scanf("%d",&dt);
        addNode(dt);
    }
    display();
}