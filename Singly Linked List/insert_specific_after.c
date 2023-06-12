#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start, *newnode, *ptr;
void addNode(int num)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    // if list is empty
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
        printf("NULL");
    }
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
void insert_specific_after(){
    int val;
    printf("Enter the value after which element to be inserted:");
    scanf("%d", &val);
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for new-node:");
    scanf("%d", &newnode->data);
    ptr = start;
    while (ptr->data != val)
    {
        ptr = ptr->next;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;

}
void main()
{
    int n, num;
    printf("Enter no of elements in the list:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter elemented to be inserted:");
        scanf("%d", &num);
        addNode(num);
    }
    insert_specific_after();
    display();
}