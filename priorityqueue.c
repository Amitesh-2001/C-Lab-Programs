#include<stdio.h>
#include<stdlib.h>

#define MAX 4

int Q[MAX],front=-1,rear=-1,data;

void insert()
{
    if(rear==(MAX-1))
    {
        printf("queue is full\n");
        return;
    }
    else
    {
        printf("enter the data\n");
        scanf("%d",&data);
        if(rear==-1&&front==-1)
        {
            rear=0;
            front=0;
            Q[rear]=data;
            return;
        }
        else
            check(data);

        rear++;
    }
}
void check(int data)
{
    int i,j;
    for( i =0;i<=rear;i++)
    {
        if(data>=Q[i])
        {
            for(j=rear+1;j>i;j--)
            {
                Q[j]=Q[j-1];

            }
            Q[i]=data;
            return;
        }
    }
    Q[i]=data;
}
void Delete()
{
    if(front == -1 && rear == -1)
        printf("queue is empty\n");
    else
    {

        printf("%d\n", Q[front]);
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


