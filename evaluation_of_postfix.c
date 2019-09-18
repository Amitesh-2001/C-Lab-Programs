#include<stdio.h>
#include<stdlib.h>

char postfix[30], ch;
int num, top = -1, op1, op2, res, s[30];

void PUSH(int num)
{
    s[++top] = num;
}
int POP()
{
    return (s[top--]);
}
void main()
{
    int j =0;
    printf("enter the postfix expression\n");
    gets(postfix);

    while(postfix[j] != '\0')
    {
        ch = postfix[j];
        if(isalpha(ch))
        {
            printf("enter the numerical value\n");
            scanf("%d", &num);
            PUSH(num);
        }
        else
        {
            op2 = POP();
            op1 = POP();
            switch(ch)
            {
                case '+' : PUSH(op1+op2);
                            break;
                case '*' : PUSH(op1*op2);
                            break;
                case '/' : PUSH(op1/op2);
                            break;
                case '-' : PUSH(op1-op2);
                            break;
            }
        }
        j++;
    }
    printf("output = %d", s[top]);
}
