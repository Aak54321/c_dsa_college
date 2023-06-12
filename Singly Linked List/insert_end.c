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
    {
        start = ptr = newnode;
    }
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
        printf("NULL");
    }
}
void insert_end()
{
    // node creation
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data for node to be inserted at the end:");
    scanf("%d", &newnode->data);
    ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newnode;
    newnode->next = NULL;
}
void main()
{
    int n, dt;
    printf("Enter no. of elements in the list:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter data:");
        scanf("%d", &dt);
        addNode(dt);
    }
    printf("List before insertion\n");
    display();
    insert_end();
    printf("List after insertion\n");
    display();
}