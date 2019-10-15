#include<stdio.h>
void toh(int n, char source, char temp, char destination)
{
     if(n<=0)
        return (0);
    if(n == 1)
        printf("move disc from %c to %c\n",source, destination);
    else
    {
        toh(n-1, source, destination, temp);
        printf("move disc from %c to %c\n", source, destination);
        toh(n-1,temp, source, destination);
    }
}

void main()
{
    int n = 3;
    char A, B, C;
    toh(n, 'A', 'B', 'C');
}
