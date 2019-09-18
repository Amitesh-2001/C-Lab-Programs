#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char infix[30], postfix[30], s[30], ch, temp;
int top = -1;

int PUSH(char ch)
{
    top = top +1;
    s[top] = ch;
}
char POP()
{
    char temp;
    temp = s[top--];
    return temp;
}
int isoperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return (1);
    else
        return (0);
}
int precedence(char ch)
{
    switch(ch)
    {
        case '^' : return(4);
                    break;
        case '*' :
        case '/' : return(3);
                    break;
        case '+' :
        case '-' : return(2);
                    break;
        default : return (0);
    }
}

void main()
{
    int i = 0, j = 0;
    printf("enter the expression:");
    gets(infix);

    while(infix[i] != '\0')
    {
        ch = infix[i];

        if(isalpha(ch))
        {
            postfix[j] = ch;
            j++;
        }
        else if(ch == '(')
        {
            PUSH(ch);
        }
        else if(isoperator(ch))
        {
            if(ch != '^')
            {
                while(top != -1 && precedence(s[top]) >= precedence(ch))
                {
                    postfix[j] = POP();
                    j++;
                }
            }
            PUSH(ch);
        }
        else if(ch == ')')
        {
            while(s[top] != '(')
            {
                postfix[j] = POP();
                j++;
            }
            temp = POP();
        }
        else
        {
            printf("invalid character");
        }

      i++;
    }

    while(top > -1)
    {
        postfix[j] = POP();
        j++;
    }
    postfix[j] = '\0';
    printf("the postfix exp is\n");
    puts(postfix);
}
