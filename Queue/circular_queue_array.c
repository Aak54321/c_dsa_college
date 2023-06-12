#include<stdio.h>
#define MAX 6
int queue[MAX];
int front=-1;
int rear = -1;

void enqueue(int dt){
    //checking whether queue is empty or not and inserting elements at the very first time
    if(front == -1){
        front=rear=0;
        queue[rear]=dt;
    }
    //check if rear is reached front part after a full circular swing
    else if((rear+1)%MAX == front){
        printf("\nQueue is Full\n");
    }
    else{
        // 👇 similar to increment but when it reaches the max value it reverts the value to 0 which makes a circular traversal
        rear=(rear+1)%MAX;
        queue[rear]=dt;
    }
}

void dequeue(){
    //checking queue is empty or not
    if(front == -1){
        printf("\nQueue is Empty\n");
    }
    //when dequeue is performed at the final element both front and rear point to same index at that time we can intialize to -1 to beginning
    else if(front == rear){
        printf("\n%d is dequeued from the queue\n",queue[front]);
        front=rear=-1;
    }
    //in dequeing elements in the middle we can use this 
    else{
        printf("\n%d is dequeued from the queue\n",queue[front]);
        front=(front+1)%MAX;
    }
}

void display(){
    if(front == -1){
        printf("\nQueue is Empty");
    }
    else{
    //initializing i to front
    int i=front;
    //printing elements until i equal to rear, then we separately print value at the rear position
    printf("\nContents of the queue:");
    while(i!=rear){
        printf("%d ",queue[i]);
        i=(i+1)%MAX;
    }
    printf("%d",queue[rear]);
    }
}

void main(){
    int choice,dt;
    printf("**************MAIN MENU***************\n");
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    do{
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("\nEnter Data:");
        scanf("%d",&dt);
        enqueue(dt);
        break;
    case 2:
        dequeue();
        break;
    case 3:
        display();
        break;
    }
    }while(choice!=4);
}