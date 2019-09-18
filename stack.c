#include<stdio.h>
#include<stdlib.h>

#define SIZE 4

int top = -1, s[SIZE], item;
void push()
{
    printf("enter the element:\n");
    scanf("%d", &item);
    if (top==(SIZE-1))
        printf("stack overflow\n");
    else
        s[++top] = item;
}

void pop()
{
    if(top== -1)
        printf("stack underflow\n");
    else
        printf("%d\n", s[top]);
        top--;
}

void display()
{
    if(top== -1)
        printf("stack is empty\n");
    else
        for(int i = 0 ; i <= top ; i++)
    {
        printf("%d\n", s[i]);
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("1.push\n2.pop\n3.display\n4.exit\n");
        printf("enter the choice:\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1 : push();
                     break;
            case 2 : pop();
                     break;
            case 3 : display();
                     break;
            case 4 : exit(0);

        }
    }
}
