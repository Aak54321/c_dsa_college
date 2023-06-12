#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start, *newnode, *ptr;
void addNode(int dt)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = dt;
    newnode->next = NULL;
    if (start == NULL)
        start = ptr = newnode;
    else
    {
        ptr->next = newnode;
        ptr = newnode;
    }
}
void display()
{
    if (start == NULL)
        printf("NULL");
    else
    {
        ptr = start;
        while (ptr != NULL)
        {
            printf("%d->", ptr->data);
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            printf("NULL");
        }
    }
}
void insert_beginning()
{
    // creating a node
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data for node to be inserted at beginning:");
    scanf("%d", &newnode->data);
    newnode->next = start;
    start = newnode;
}
void main()
{
    int n, dt;
    printf("Enter no. of elements in the list:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter the element:");
        scanf("%d", &dt);
        addNode(dt);
    }
    printf("List before insertion\n");
    display();
    insert_beginning();
    printf("List after insertion:");
    display();
}