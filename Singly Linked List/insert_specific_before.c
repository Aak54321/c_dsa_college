#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL, *newnode, *ptr;
void addNode(int num)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
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
    ptr = start;
    if (start == NULL)
        printf("NULL");
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    if (ptr == NULL)
        printf("NULL");
}
void main()
{
    int n, num;
    printf("Enter no. of elements in the list:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter element:");
        scanf("%d", &num);
        addNode(num);
    }
    struct node *preptr;
    preptr = ptr = start;
    int val;
    printf("Enter the value before which element is inserted before:");
    scanf("%d", &val);
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for new-node:");
    scanf("%d", &newnode->data);
    while (ptr->data!=val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    newnode->next = ptr;
    preptr->next = newnode;
    display();
}
