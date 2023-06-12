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
void del_end(){
    if(start == NULL){
        printf("List is empty,Nothing to delete!!");
    }
    else{
    struct node *preptr;
    ptr=start;
    while(ptr->next!=NULL){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
}
}
void main(){
    int n,dt;
    printf("Enter no. of elements in the list:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("Enter data:");
        scanf("%d",&dt);
        create(dt);
    }
    printf("List before deletion\n");
    display();
    del_end();
    printf("\nList After deletion\n");
    display();
}