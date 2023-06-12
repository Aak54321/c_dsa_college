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
    {
        printf("List is empty");
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
void del_specific()
{
    int val;
    printf("\nEnter value to be deleted:");
    scanf("%d", &val);
    struct node *preptr;
    ptr = preptr = start;
    while (/*pre*/ ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
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
        create(dt);
    }
    printf("\nlist before deletion\n");
    display();
    del_specific();
    printf("\nlist after deletion\n");
    display();
}