#include <stdio.h>
#include <stdlib.h>
// creating our node
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
// initializing some essential pointers to work on
struct node *start, *newnode, *ptr;
// function to create a node
void create(int dt)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = dt;
    newnode->next = NULL;
    // things to do if list is created for first time
    if (start == NULL)
    {
        newnode->prev = NULL;
        start = ptr = newnode;
    }
    // things to do if list is already created
    else
    {
        ptr->next = newnode;
        newnode->prev = ptr;
        ptr = newnode; /*👈 because newnode will be changed afterwards,so ptr is updated here*/
    }
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
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}
void insert_beginning()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to be inserted at the beginning:");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=start;
    start=newnode;
}
void main()
{
    int n, dt;
    printf("Enter no. of elements in the list:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter data:");
        scanf("%d", &dt);
        create(dt);
    }
    printf("List before insertion\n");
    display();
    insert_beginning();
    printf("List after insertion\n");
    display();
}