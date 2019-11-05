#include <stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*llink;
	struct node*rlink;
};
struct node*start=NULL;

void insertbeg()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the element\n");
	scanf("%d",&temp->data);
	temp->llink=NULL;
	temp->rlink=NULL;

	if(start == NULL)
	{
		start=temp;
	}
	else
	{
		temp->rlink=start;
		start->llink=temp;
		start=temp;
	}
}

void insertorder()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the element\n");
	scanf("%d",&temp->data);
	temp->llink=NULL;
	temp->rlink=NULL;

	if(start == NULL)
	{
		start=temp;
	}
	else if(temp->data < start->data)
	{
		insertbeg();
	}
	else
	{
		struct node*p;
		p=start;
		while(p->rlink!=NULL && p->data <temp->data)
		{
			p=p->rlink;
		}	
		

		if(p->rlink ==NULL && p->data<temp->data)
		{
			p->rlink=temp;
			temp->llink=p;
		}
		else
		{
			temp->rlink=p;		
			p->llink->rlink=temp;
			temp->llink=p->llink;
			p->llink=temp;
		}
	}
}		

void display()
{
	struct node *p;
	if(start==NULL)
		printf("empty\n");
	else
	{
		p=start;
		while(p->rlink != NULL)
		{
			printf("%d-->", p->data);
			p=p->rlink;
		}
		printf("%d-->", p->data);
		printf("\n");
	}
}

void main()
{
	int ch;
	while(1)
	{
		printf("1.insertbeg\n2.display\n3.insertorder\n4.exit\n");
		printf("enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : insertbeg();
				 break;
			case 2 : display();
				 break;
			case 3 : insertorder();
				 break;
			case 4 : exit(0);
		}
	}
}		
