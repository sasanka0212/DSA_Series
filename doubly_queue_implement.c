#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int Queue[10],front=-1,rear=-1;
void insertFront();
void insertRear();
void deleteFront();
void deleteRear();
void display();
int main()
{
    int ch;
    while(1){
        printf("\nenter 1 to insert front:\nenter 2 to insert rear:\nenter 3 to delete front:\nenter 4 to delete rear:\nenter 5 to display Queue:\npress any key to exit:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insertFront();
                break;
            case 2:
                insertRear();
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
void insertFront()
{
    if(front==0)
        printf("\nQueue is full.");
    else{
        int item;
        printf("\nenter data:");
        scanf("%d",&item);
        if(front==-1 && rear==-1)
        {
            front=0;
            rear=0;
        }
        else
        {
            front=front-1;
        }
        Queue[front]=item;
    }
}
void insertRear()
{
    if(rear==MAX-1)
        printf("\nQueue is full.");
    else{
        int item;
        printf("\nenter data:");
        scanf("%d",&item);
        if(rear==-1)
        {
            front=0;
            rear=0;
        }
        else
        {
            rear=rear+1;
        }
        Queue[rear]=item;
    }
}
void deleteFront()
{
    if(front==-1)
        printf("\nQueue is empty.");
    else{
        int d=Queue[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=front+1;
        }
        printf("\ndeleted data:%d",d);
    }
}
void deleteRear()
{
    if(rear==-1)
        printf("\nQueue is empty.");
    else{
        int d=Queue[rear];
        if(rear==front)
        {
            rear=-1;
            front=-1;
        }
        else
        {
            rear=rear-1;
        }
        printf("\ndeleted data:%d",d);
    }
}
void display()
{
    if(front==-1)
        printf("\nQueue is empty.");
    else{
        int i;
        for(i=front;i<=rear;i++)
            printf("[%d]",Queue[i]);
    }
}
