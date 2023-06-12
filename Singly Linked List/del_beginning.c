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
    if(start == NULL)
        start=ptr=newnode;
    else{
        ptr->next=newnode;
        ptr=newnode;
    }
}
void display(){
if(start == NULL)
    printf("list is empty\n");
else{
    ptr=start;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
}
void del_beg(){
if(start == NULL){
    printf("List is empty!,Nothing to delete");
}
ptr=start;
start=start->next;
free(ptr);
}
void main(){
int n,dt;
printf("Enter no. of elements in the list:");
scanf("%d",&n);
for(int i=1;i<=n;i++){
    printf("Enter element:");
    scanf("%d",&dt);
    create(dt);
}
printf("list before deletion\n");
display();
del_beg();
printf("\nlist after deletion\n");
display();
}