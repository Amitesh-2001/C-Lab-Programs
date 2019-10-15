#include<stdio.h>
#include<stdlib.h>

#define SIZE 4

int rear = -1, front = -1, Q[SIZE], item, ditem;

void insert()
{
    if(rear == (SIZE-1))
        printf("queue is full\n");
    else
    {
        printf("enter the element\n");
        scanf("%d", &item);
        if(rear == -1 && front == -1)
        {
            rear = 0 ;
            front = 0 ;
        }
        else
        {
            rear = rear +1 ;
        }
        Q[rear] = item;
    }

}

void Delete()
{
    if(front == -1 && rear == -1)
        printf("queue is empty\n");
    else
    {
        ditem = Q[front];
        printf("%d", ditem);
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = front + 1 ;
        }
    }
}

void display()
{
    if(rear == -1 && front == -1)
        printf("empty\n");
    else
    {
        for(int i =front ; i<=rear ; i++)
        {
            printf("%d\n", Q[i]);
        }
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
