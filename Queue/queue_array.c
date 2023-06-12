#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int num)
{
    if (rear == MAX - 1)
    {
        printf("\nOverflow\n");
    }
    else if(front == -1 && rear == -1){
        front++;
        rear++;
        queue[rear]=num;
    }
    else
    {
        rear++;
        queue[rear] = num;
    }
}
void dequeue()
{
    if (front == -1)
    {
        printf("\nUnderflow\n");
    }
    else if (front == rear)
    {
        printf("\n%d is popped out of queue\n",queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("\n%d is popped out of queue\n", queue[front]);
        front++;
    }
}
void display()
{
    if(front == -1){
        printf("\nEmpty Queue\n");
    }
    else{
    printf("The contents of the queue are:");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
    }
}
void main()
{
    printf("***********MAIN MENU***********\n");
    printf("1.enqueue\n2.dequeue\n3.Display\n4.Quit\n");
    int choice,num;
    do
    {
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter data:");
            scanf("%d", &num);
            enqueue(num);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        }

    } while (choice != 4);
}