#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
void create(struct node *tree)
{
    if (islchild(tree)==1)
    {
        struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter the data\n");
        scanf("%d", &temp->data);
        temp->llink=NULL;
        temp->rlink=NULL;
        tree->llink=temp;
        create(temp);
    }
    else
        tree->llink=NULL;

    if (isrchild(tree)==1)
    {
        struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter the data\n");
        scanf("%d", &temp->data);
        temp->llink=NULL;
        temp->rlink=NULL;
        tree->rlink=temp;
        create(temp);
    }
    else
        tree->rlink=NULL;
}
int islchild(struct node *tree)
{
    int ch;
    printf("do you want a left child for %d?\n1.Yes\n2.No\n",tree->data);
    scanf("%d",&ch);
    return(ch);
}
int isrchild(struct node *tree)
{
    int ch;
    printf("do you want a right child for %d?\n1.Yes\n2.No\n",tree->data);
    scanf("%d",&ch);
    return(ch);
}
void inorder(struct node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->llink);
        printf("%d",tree->data);
        inorder(tree->rlink);
    }

}
void main()
{
    struct node *root;
    root=(struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d", &root->data);
    root->llink=NULL;
    root->rlink=NULL;
    create(root);
    printf("the inorder traversal of the tree is:\n");
    inorder(root);
}
