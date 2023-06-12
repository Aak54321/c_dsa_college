#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode, *top=NULL,*ptr;
void push()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data:");
    scanf("%d", &newnode->data);
    // addressing stack overflow(in reality it's heap overflow disguising as stack overflow)
    if (newnode == NULL)
    {
        printf("\nStack Overflow");
    }
    // Otherwise add an element at the beginning
    else
    {
        newnode->next = top;
        top = newnode;
        printf("\nElement is Pushed to the Stack\n");
    }
    
}

void pop()
{
    // Addressing stack Underflow
    if (top == NULL)
    {
        printf("\nStack Underflow");
    }
    else{
        printf("\n%d is Popped out of the Stack",top->data);
        ptr=top;
        top=top->next;
        free(ptr);
    }
}

void display()
{
    ptr=top;
    printf("\nContents of the Stack\n");
    while(ptr!=NULL){
        printf("\t%d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

void main(){
    int choice;
    printf("*********MAIN MENU**************");
    printf("\n1. push\n2. pop\n3. display\n4.exit\n");
    do{
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
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
    }while(choice != 4);
}