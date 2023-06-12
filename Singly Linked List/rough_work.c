#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start,*newnode,*ptr;
void create(int dt){
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=dt;
    newnode->next=NULL;
    if(start == NULL){
        start=ptr=newnode;
    }
    else{
        ptr->next=newnode;
        ptr=newnode;
        
    }
}
void display(){
    if(start == NULL){
        printf("List is empty");
    }
    else{
        ptr=start;
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}
void /*fn you want to practice*/(){
    
}

void main(){

}