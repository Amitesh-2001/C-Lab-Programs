#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
struct node *start = NULL;

void ispallindrome()
{
    struct node *ptr, *p;
    ptr=start;
    while(ptr->rlink != NULL)
    {
        ptr=ptr->rlink;
    }
    p=start;
    while(p != ptr && ptr != p->llink)
    {
        if(p->data != ptr->data)
            break;

        p=p->rlink;
        ptr=ptr->llink;

    }
    if(p->data != ptr->data)
        printf("it is not a pallindrome\n");
    else
        printf("it is a pallindrome\n");


}
void insertbeg()
{
    struct node *temp ;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d", &temp->data);
    temp->llink=NULL;
    temp->rlink=NULL;

    if(start == NULL)
        start = temp;
    else
    {
        temp->rlink=start;
        start->llink=temp;
        start=temp;
    }
}
void insertend()
{
    struct node *temp ;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d", &temp->data);
    temp->llink=NULL;
    temp->rlink=NULL;

    if(start == NULL)
        start = temp;
    else
    {
        struct node *p;
        p=start;
        while(p->rlink!=NULL)
            p=p->rlink;
        temp->llink=p;
        p->rlink=temp;
    }
}
void insertpos()
{
    int pos,count=0;
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        count++;
        p=p->rlink;
    }

    printf("enter the pos\n");
    scanf("%d",&pos);

    if(pos==1)
        insertbeg();
    else if(pos==count+1)
        insertend();
    else if(pos>1&&pos<=count)
    {
        struct node *temp ;
        int i;
        temp = (struct node*)malloc(sizeof(struct node));
        printf("enter the data\n");
        scanf("%d", &temp->data);
        temp->llink=NULL;
        temp->rlink=NULL;
        p=start;
        for(i =1;i<pos-1;i++)
        {
            p=p->rlink;
        }
        temp->rlink=p->rlink;
        p->rlink=temp;
        temp->llink=p;
        temp->rlink->llink=temp;
    }
    else
        printf("invalid location\n");

}
void deletebeg()
{
    struct node *p;
    if(start == NULL)
        printf("empty\n");
    else if(start->rlink==NULL)
        start=NULL;
    else
    {
        p=start;
        p->llink=NULL;
        start=p->rlink;
        free(p);
    }
}
void deleteend()
{
    struct node *p;
    if(start == NULL)
        printf("empty\n");
    else if(start->rlink==NULL)
        start=NULL;
    else
    {
        p=start;
        while(p->rlink!=NULL)
            p=p->rlink;
        p->llink->rlink=NULL;
        free(p);
    }
}
void deletepos()
{
     int pos,count=0;
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        count++;
        p=p->rlink;
    }

    printf("enter the pos\n");
    scanf("%d",&pos);

    if(pos==1)
       deletebeg();
    else if(pos==count)
        deleteend();
    else if(pos>1&&pos<count)
    {
        int i;
        p=start;
        for(i =1;i<pos;i++)
        {
            p=p->rlink;
        }
        p->llink->rlink=p->rlink;
        p->rlink->llink=p->llink;
        free(p);
    }
    else
        printf("invalid location\n");
}
void display()
{
    if(start == NULL)
        printf("empty\n");
    else
    {
        struct node *p;
        p=start;
        while(p!=NULL)
        {
            printf("%d-->",p->data);
            p=p->rlink;
        }
        printf("\n");
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("1.insertbeg\n2.display\n3.insertend\n4.insertpos\n5.deletebeg\n6.deleteend\n7.deletepos\n8.ispalindrome\n9.exit\n");
        printf("enter the choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : insertbeg();
                     break;
            case 2 : display();
                     break;
            case 3 : insertend();
                     break;
            case 4 : insertpos();
                     break;
            case 5 : deletebeg();
                     break;
            case 6 : deleteend();
                     break;
            case 7 : deletepos();
                     break;
            case 8 : ispalindrome();
                     break;
            case 9 : exit(0);
        }
    }
}
