/*
Scrivere un programma in C che acquisisce un numero maggiore di 1. 
Il programma stabilisce se il numero è primo o meno e visualizza un 
apposito messaggio con il risultato.
*/

#include<stdio.h>

int main()
{
    int n, i = 2, cond = 1;
    scanf("%d", &n);
    while(i * i <= n && cond){
        cond = n % i != 0;
        i++;
    }

    if(cond)
    	printf("Primo\n");
    else
    	printf("Non primo\n");

    return 0;
}