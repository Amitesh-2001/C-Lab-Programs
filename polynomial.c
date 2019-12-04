#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int power;
    int coeff;
    struct node *link;
};
struct node *start=NULL, *temp, *ptr;

void create()
{
    temp = (struct node*)malloc(sizeof(struct node*));
    printf("enter the coeff and power\n");
    scanf("%d%d", &temp->coeff,&temp->power);
    temp->link=NULL;

    if(start==NULL)
        start=temp;
    else if(start->power<=temp->power)
    {
        temp->link=start;
        start=temp;
    }
    else
    {
        struct node *curptr;
        ptr=start;
        while(ptr!=NULL&&ptr->power>=temp->power)
        {
            curptr=ptr;
            ptr=ptr->link;
        }
        if(ptr==NULL)
            curptr->link=temp;
        else
        {
            temp->link=curptr->link;
            curptr->link=temp;
        }
    }
}

void display()
{
    if(start==NULL)
        printf("empty\n");
    else
    {
        ptr=start;
        while(ptr!=NULL)
        {
            printf("%d:%d-->", temp->coeff,temp->power);
            ptr=ptr->link;
        }
        printf("\n");
    }
}
void evaluate()
{
    int sum=0,x;
    if(start==NULL)
        printf("empty");
    else
    {
        printf("enter the alue of x\n");
        scanf("%d",&x);
        ptr=start;
        while(ptr!=NULL)
        {
            sum=sum+ptr->coeff*pow(x,ptr->power);
            ptr=ptr->link;
        }
    }
    printf("the expression result is %d\n",sum);
}
void main()
{
    int ch;
    while(1)
    {
        printf("1.insert\n2.display\n3.evaluate\n4.exit\n");
        printf("enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : create();
                     break;
            case 2 : display();
                     break;
            case 3 : evaluate();
                     break;
            case 4 : exit(0);
        }
    }
}
