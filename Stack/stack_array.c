#include <stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;
void push()
{
    // condition to check if we reached the upper most part of the stack
    if (top == MAX - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        int data;
        printf("\nEnter data:");
        scanf("%d", &data);
        top++;
        stack[top] = data;
    }
}

void pop()
{
    // condition to check if we reached the lower most part of the stack and no more element to pop out
    if (top == -1)
    {
        printf("\nStack Underflow");
    }
    else
    {
        printf("%d is popped out", stack[top]);
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is Empty");
    }
    else
    {
        printf("Contents of the Stack are:");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}

void main()
{
    int choice;
    printf("*************MAIN MENU*****************");
    printf("\nEnter 1 to Push an element to the stack");
    printf("\nEnter 2 to Pop an element from the stack");
    printf("\nEnter 3 to display the contents of the stack");
    printf("\nEnter 4 to exit");
    do
    {
        printf("\n\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        }
    } while (choice != 4);
}