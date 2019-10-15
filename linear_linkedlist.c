#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *start = NULL;

void insertend()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d", &temp->data);
    temp -> link = NULL;

    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        struct node *p;
        p = start;
        while(p->link != NULL)
        {
            p = p -> link;
        }
        p -> link = temp;

    }
}
void insertbeg()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d", &temp->data);
    temp -> link = NULL;

    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->link = start;
        start = temp;
    }
}
void insertmid()
{
    struct node *temp, *p;
    int pos;
    int count = 0;

    printf("enter the pos\n");
    scanf("%d", &pos);

    p = start;
    while(p != NULL)
    {
        count++;
        p = p->link;
    }
    if(pos == 1)
    {
        insertbeg();
    }
    else if(pos == count+1)
    {
        insertend();
    }
    else if(pos>1 && pos<= count)
    {
        struct node *p;
        int i =1;
        temp = (struct node *)malloc(sizeof(struct node));
        printf("enter the data\n");
        scanf("%d", &temp->data);
        temp -> link = NULL;
        p = start;
        for(i = 1; i<pos-1; i++)
        {
            p = p->link;
        }
        temp -> link = p -> link;
        p -> link = temp;
    }
    else
        printf("invalid location\n");
}

void deleteend()
{
    struct node *p, *cur;

    if(start == NULL)
        printf("empty\n");

    cur = start;
    p = cur->link;

    if(cur->link == NULL)
    {
        start = cur->link;
        free(cur);
    }
    else
    {
        while(p->link != NULL)
        {
            p = p->link;
            cur = cur->link;
        }
        cur->link = p->link;
        free(p);
    }

}

void deletebeg()
{
    struct node *p ;

    if(start == NULL)
        printf("empty\n");

    p = start;


    if(p->link == NULL)
    {
        start = p->link;
        free(p);
    }
    else
    {
        start = p->link;
        p->link = NULL;
        free(p);
    }
}

void deletemid()
{
  struct node *temp, *p;
    int pos;
    int count = 0;

    printf("enter the pos\n");
    scanf("%d", &pos);

    p = start;
    while(p != NULL)
    {
        count++;
        p = p->link;
    }
    if(pos == 1)
    {
        deletebeg();
    }
    else if(pos == count)
    {
        deleteend();
    }
    else if(pos>1 && pos< count)
    {
        struct node *p, *cur;
        int i =1;

        cur = start;
        p = cur->link;

        for(i = 1; i<pos-1; i++)
        {
            p = p->link;
            cur = cur->link;
        }
        cur -> link = p -> link;
        p -> link = NULL;
    }
    else
        printf("invalid location\n");

}

void delete_item()
{
    struct node *p, *cur;
    int item;

    printf("enter the element to be deleted\n");
    scanf("%d", &item);

    cur = start ;

    if(cur->data == item)
    {
        deletebeg();
    }
else
{   
    p = cur->link;
    while(p->link != NULL)
    {
        if(p->data == item)
        {
            cur->link = p->link;
            p->link = NULL;
            free(p);
        }
            p = p->link;
            cur = cur->link;
    }
            if(p->data ==item)
            {
               deleteend();
            }
}

void display()
{
    struct node *temp;
    temp = start;
    if(start == NULL)
        printf("empty\n");
    else
    {
        while(temp != NULL)
        {
            printf("%d-->",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("1.insertatend\n2.display\n3.insertbeg\n4.insertmid\n5.deleteend\n6.deletebeg\n7.deletemid\n8.deleteitem\n9.exit\n");
        printf("enter the choice\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1 : insertend();
                     break;
            case 2 : display();
                     break;
            case 3 : insertbeg();
                     break;
            case 4 : insertmid();
                     break;
            case 5 : deleteend();
                     break;
            case 6 : deletebeg();
                     break;
            case 7 : deletemid();
                     break;
            case 8 : delete_item();
                     break;
            case 9 : exit(0);
        }
    }
}
