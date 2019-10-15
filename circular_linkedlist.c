#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *last = NULL;

void insertend()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d", &temp->data);
    temp -> link = NULL;

    if(last == NULL)
    {
        last = temp;
        last->link = last;
    }
    else
    {
        temp->link = last->link;
        last->link = temp;
        last = temp;
    }
}

void insertbeg()
{
 struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d", &temp->data);
    temp -> link = NULL;

    if(last == NULL)
    {
        last = temp;
        last->link = last;
    }
    else
    {
        temp->link = last->link;
        last->link = temp;

    }
}

void insertmid()
{
   struct node *temp, *p;
    int pos;
    int count = 0;

    printf("enter the pos\n");
    scanf("%d", &pos);

    p = last->link;
    while(p != last)
    {
        count++;
        p = p->link;
    }
    count++;
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
        p = last->link;
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
    struct node *cur;

    if(last == NULL)
        printf("empty\n");

    cur = last->link;

    if(last->link == last)
    {
        last = NULL;
        free(last);
    }
    else
    {
        while(cur->link != last)
        {
            cur = cur->link;
        }
        cur->link = last->link;
        free(last);
        last = cur;
    }

}

void deletebeg()
{
    struct node *p ;

    if(last == NULL)
        printf("empty\n");

    p = last->link;

    if(last->link == last)
    {
        last = NULL;
        free(last);
    }
    else
    {
        last->link = p->link;
        p->link = NULL;
        free(p);
    }
}


void display()
{
    struct node *temp;

    if(last == NULL)
        printf("empty\n");
    else
    {
        temp = last->link;
        while(temp != last)
        {
            printf("%d-->",temp->data);
            temp = temp->link;
        }
        printf("%d-->", temp->data);
        printf("\n");
    }
}

void delete_item()
{
    struct node *p, *cur;
    int item;

    printf("enter the element to be deleted\n");
    scanf("%d", &item);

    cur = last->link ;


    if(cur->data == item)
    {
        deletebeg();
    }
    else
    {
        p = cur->link;
        while(p != last)
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
        if(p->data == item)
            {
                deleteend();
            }
    }
}

void deletemid()
{
  struct node *temp, *p;
    int pos;
    int count = 0;

    printf("enter the pos\n");
    scanf("%d", &pos);

    p = last->link;
    while(p != last)
    {
        count++;
        p = p->link;
    }
    count++;
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

        cur = last->link;
        p = cur->link;

        for(i = 1; i<pos-1; i++)
        {
            p = p->link;
            cur = cur->link;
        }
        cur -> link = p -> link;
        p -> link = NULL;
        free(p);
    }
    else
        printf("invalid location\n");

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
