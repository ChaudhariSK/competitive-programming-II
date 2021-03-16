#include <stdio.h>
#include <stdlib.h>

void carmichael(long n);
long power(long x, long n);
int prime(long n);
long bigmod(long b, long p, long m);

int main()
{
    long n;
    while((scanf("%ld", &n)==1)&&(n!=0))
    {
        if(prime(n))
        {
            printf("%ld is normal.\n", n);
        }
        else
        {
            carmichael(n);
        }
    }
    return 0;
}

void carmichael(long n)
{
    long i, flag=1;
    for(i=3; i<n; i++)
    {
        if(bigmod(i, n, n)!=i)
        {
            flag=0;
            printf("%ld is normal.\n", n);
            break;
        }
    }
    if(flag==1)
    {
        printf("The number %ld is a Carmichael number.\n", n);
    }
}

long power(long x, long n)
{
    long i, mul=1;
    for(i=0; i<n; i++)
    {
        mul*=x;
    }
    return mul;
}

int prime(long n)
{
    int i;
    for(i=2; i*i<=n; i++)
    {
        if((n%i)==0)
        {
            return 0;
        }
    }
    return 1;
}

long bigmod(long b, long p, long m)
{
    if(p==0)
    {
        return 1;
    }
    else if (p%2==0)
    {
        return (bigmod(b, p/2, m)*bigmod(b, p/2, m))%m;
    }
    else
    {
        return ((b%m)*bigmod(b, p-1, m))%m;
    }
}
