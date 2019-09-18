#include<stdio.h>

int gcd(int a, int b)
{
    while(a!=b)
    {
        if(a > b)
            return gcd(b, a-b);
        else if(b>a)
            return gcd(b-a, a);
    }
    if(a==b)
    {
        return a;
    }
}
void main()
{
    int a, b, result;
    printf("enter two numbers\n");
    scanf("%d\n%d", &a, &b);
    result = gcd(a,b);
    printf("ans is %d", result);
}
