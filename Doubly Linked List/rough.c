#include<stdio.h>
#include<stdlib.h>
// creating our node
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start,*newnode,*ptr;
void create(int dt){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->data=dt;
    newnode->next=NULL;
    if(start == NULL){
        start=ptr=newnode;
    }
    else{
        ptr->next=newnode;
        newnode->prev=ptr;
        ptr=newnode;
    }
}