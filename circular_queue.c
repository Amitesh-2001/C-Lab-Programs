#include<stdio.h>
#include<stdlib.h>
#define SIZE 3

int rear = -1, front = -1, CQ[SIZE], item,  i;

void insert()
{
    if(rear == (front - 1) || (front == 0 && rear == (SIZE-1)))
        printf("overflow\n");
    else
    {
        printf("enter the element\n");
        scanf("%d", &item);

        if(front == -1 && rear == -1)
            front = 0;

        rear = (rear + 1) % SIZE ;
        CQ[rear] = item;
    }
}

void Delete()
{
    if(rear == -1 && front == -1)
    {
        printf("underflow\n");
    }
    else
    {

        printf("%d\n", CQ[front]);

        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % SIZE ;
    }
}

void display()
{
    if(rear == -1 && front == -1)
        printf("empty\n");
    else
    {
        for( i = front ; i != rear ; i = (i+1)%SIZE)
        {
            printf("%d\n", CQ[i]);
        }
        printf("%d\n", CQ[i]);
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("1.insert\n2.delete\n3.display\n4.exit\n");
        printf("enter the choice\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1 : insert();
                     break;
            case 2 : Delete();
                     break;
            case 3 : display();
                     break;
            case 4 : exit(0);
        }
    }
}
