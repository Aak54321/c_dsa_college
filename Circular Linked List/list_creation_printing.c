#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start, *newnode, *ptr;
void create(int dt)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = dt;
    newnode->next=start;
    if (start == NULL)
    {
        start = ptr = newnode;
    }
    else
    {
        ptr->next = newnode;
        ptr=newnode;
  
    }
        //   ptr->next=start;
}
void display()
{
    if (start == NULL)
    {
        printf("list is empty");
    }
    else
    {
        ptr = start;
        while(ptr->next!=start){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("%d",ptr->data);
    }
}
void main(){
    int n,dt;
    printf("Enter no. of elements in the list:");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter data:");
        scanf("%d",&dt);
        create(dt);
    }
    display();
}