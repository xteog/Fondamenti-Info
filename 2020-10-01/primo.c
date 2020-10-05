#include<stdio.h>

int main()
{
    int n, i = 2, cond = 1;
    scanf("%d", &n);
    while(i * i <= n && cond){
        cond = n % i != 0;
        i++;
    }
    printf("%d", cond);
    return 0;
}